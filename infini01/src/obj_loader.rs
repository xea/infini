use crate::model::Model;
use crate::vertex::{Vertex, Normal};
use wavefront_obj::obj::Primitive;
use std::fs::File;
use std::io::Read;

pub struct ObjLoader;

impl ObjLoader {
    pub fn load_model(model_name: &str) -> Model {
        let mut model_data = String::new();

        // First step: read object data from the given file
        let mut model_file = File::open(format!("../objects/{}.obj", model_name))
            .expect("Requested model file could not be found");

        model_file.read_to_string(&mut model_data)
            .expect("Requested model file could not be read");

        let obj_set = wavefront_obj::obj::parse(model_data)
            .expect("Requested model could not be parsed");

        let objects = obj_set.objects;

        let vertices: Vec<Vertex> = objects.iter()
            .flat_map(|object| &object.vertices)
            .map(|vertex| Vertex::new(vertex.x, vertex.y, vertex.z))
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
            .map(|normal| Normal { normal: [ normal.x, normal.y, normal.z] })
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
}
