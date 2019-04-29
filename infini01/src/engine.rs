use glium::{Display, Program, Surface, DrawParameters, DepthTest, Depth};
use glutin::{ContextBuilder, Event, EventsLoop, WindowBuilder, WindowEvent};
use wavefront_obj::obj::Primitive;
use std::fs::File;
use std::io::Read;

use crate::model::Model;
use crate::render_object::RenderObject;
use crate::vertex::{Vertex, Normal};
use crate::obj_loader::ObjLoader;

const APP_TITLE: &'static str = "infini01";

pub struct Engine {
    events_loop: EventsLoop,
    objects: Vec<RenderObject>,
    display: Display,
    shader_program: Option<Program>,
}

impl Engine {
    pub fn new() -> Self {
        let events_loop = EventsLoop::new();
        let window_builder = WindowBuilder::new()
            .with_title(APP_TITLE);

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
        ObjLoader::load_model(model_name)
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
                object.tick();

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
