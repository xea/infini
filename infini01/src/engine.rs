use glium::{Display, Program, Surface, DrawParameters, DepthTest, Depth};
use glutin::{ContextBuilder, Event, EventsLoop, WindowBuilder, WindowEvent};
use wavefront_obj::obj::Primitive;
use std::fs::File;
use std::io::Read;

use crate::model::Model;
use crate::render_object::RenderObject;

type VertexCoord = f32;

/// Defines a single vertex with x, y, z coordinates
#[derive(Copy, Clone, Debug)]
pub struct Vertex {
    pub position: [VertexCoord; 3]
}

impl Vertex {
    pub fn new(x: VertexCoord, y: VertexCoord, z: VertexCoord) -> Self {
        Self { position: [ x, y, z ] }
    }
}

implement_vertex!(Vertex, position);

/// Defines a single vertex with x, y, z coordinates
#[derive(Copy, Clone, Debug)]
pub struct Normal {
    pub normal: [VertexCoord; 3]
}

impl Normal {
    pub fn new(x: VertexCoord, y: VertexCoord, z: VertexCoord) -> Self {
        Self { normal: [ x, y, z ] }
    }
}

implement_vertex!(Normal, normal);

pub struct Engine {
    events_loop: EventsLoop,
    objects: Vec<RenderObject>,
    display: Display,
    shader_program: Option<Program>
}

impl Engine {
    pub fn new() -> Self {
        let events_loop = EventsLoop::new();
        let window_builder = WindowBuilder::new()
            .with_title("vis-rs 3");

        let context_builder = ContextBuilder::new()
            .with_depth_buffer(24);
        let display = Display::new(window_builder, context_builder, &events_loop).unwrap();

        Self {
            events_loop,
            objects: vec![],
            shader_program: None,
            display
        }
    }

    pub fn add_object(&mut self, model: Model) {
        let object = RenderObject::new(&model, &self.display);
        self.objects.push(object);
    }

    #[allow(unused_imports)]
    pub fn add_background(&mut self) {
        let model = Model::new(vec![
            Vertex::new(-1.0,  1.0, 0.0),
            Vertex::new(-1.0, -1.0, 0.0),
            Vertex::new( 1.0,  1.0, 0.0),
            Vertex::new( 1.0, -1.0, 0.0)
        ], vec![ 0, 1, 2, 1, 2, 3 ], vec![]);

        self.add_object(model);
    }

    #[allow(unused_imports)]
    pub fn add_triangle(&mut self) {
        let vertices = vec![
            Vertex::new( 0.0, 0.5, 0.0),
            Vertex::new(-0.33, -0.17, 0.0),
            Vertex::new( 0.33, -0.17, 0.0)
        ];

        let indices = vec![ 0, 1, 2 ];
        let normals = vec![
            Normal::new( 0.0, 0.5, 0.5),
            Normal::new(-0.33, -0.17, 0.5),
            Normal::new( 0.33, -0.17, 0.5)
        ];

        let model = Model::new(vertices, indices, normals);
        self.add_object(model);
    }

    pub fn attach_shader(&mut self, shader_name: &str) {
        let mut vertex_file = File::open(format!("../shader/{}.vs.glsl", shader_name)).unwrap();
        let mut fragment_file = File::open(format!("../shader/{}.fs.glsl", shader_name)).unwrap();

        let mut vertex_shader_src = String::new();
        let mut fragment_shader_src = String::new();

        vertex_file.read_to_string(&mut vertex_shader_src).unwrap();
        fragment_file.read_to_string(&mut fragment_shader_src).unwrap();

        self.shader_program = Some(Program::from_source(&self.display, &vertex_shader_src, &fragment_shader_src, None).unwrap());
    }

    pub fn load_model(&self, model_name: &str) -> Model {
        let mut model_file = File::open(format!("../objects/{}.obj", model_name)).unwrap();
        let mut model_data = String::new();
        model_file.read_to_string(&mut model_data).unwrap();

        //let model_data = include_str!("../objects/trunk.obj");
        let obj_set = wavefront_obj::obj::parse(model_data).unwrap();
        let objects = obj_set.objects;

        let vertices: Vec<Vertex> = objects.iter()
            .flat_map(|object| &object.vertices)
            .map(|vertex| Vertex::new(vertex.x as f32, vertex.y as f32, vertex.z as f32))
            .collect();

        let indices: Vec<u32> = objects.iter()
            .flat_map(|object| &object.geometry)
            .flat_map(|geometry| &geometry.shapes)
            .map(|shape| &shape.primitive)
            .flat_map(|primitive| match primitive {
                Primitive::Triangle((v_0, _, _), (v_1, _, _), (v_2, _, _)) => {
                    vec![ *v_0 as u32, *v_1 as u32, *v_2 as u32 ]
                },
                _ => unimplemented!()
            })
            .collect();

        let normals: Vec<Normal> = objects.iter()
            .flat_map(|object| &object.normals)
            .map(|normal| Normal { normal: [ normal.x as f32, normal.y as f32, normal.z as f32 ] })
            .collect();

        let nindx: Vec<Normal> = objects.iter()
            .flat_map(|object| &object.geometry)
            .flat_map(|geometry| &geometry.shapes)
            .map(|shape| &shape.primitive)
            .flat_map(|primitive| match primitive {
                Primitive::Triangle((_, _, n_0), (_, _, n_1), (_, _, n_2)) => {
                    vec![
                        normals[n_0.unwrap()],
                        normals[n_1.unwrap()],
                        normals[n_2.unwrap()]
                    ]
                },
                _ => unimplemented!()

            })
            .collect();

        Model::new(vertices, indices, nindx)
    }

    pub fn main_loop(&mut self) {
        let mut close_requested = false;
        let params = DrawParameters {
            depth: Depth {
                test: DepthTest::IfLess,
                write: true,
                .. Default::default()
            },
            .. Default::default()
        };

        while !close_requested {
            let mut target = self.display.draw();

            target.clear_color_and_depth((0.0, 0.0, 0.0, 1.0), 1.0);

            for object in &mut self.objects {
                object.rotate([ 1.0, 1.0, 1.0 ]);
                //object.translate([ 0.01, 0.0, 0.0 ]);
                target.draw(
                    (&object.vertex_buffer, &object.normals),
                    &object.index_buffer,
                    self.shader_program.as_ref().unwrap(),
                    &object.uniform, &params)
                    .unwrap();
            }

            target.finish().unwrap();

            self.events_loop.poll_events(|event| {
                match event {
                    Event::WindowEvent { event, .. } => match event {
                        WindowEvent::CloseRequested => close_requested = true,
                        _ => ()
                    },
                    _ => ()
                }
            })
        }
    }
}
