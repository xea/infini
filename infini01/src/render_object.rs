use super::model::Model;
use crate::vertex::{Vertex, Normal};
use glium::backend::Facade;
use glium::{VertexBuffer, IndexBuffer};
use glm::{Matrix4, vec3};

use glium::uniforms::{AsUniformValue, Uniforms, UniformValue};
use glium::index::PrimitiveType;

pub struct RenderObject {
    pub vertex_buffer: VertexBuffer<Vertex>,
    pub index_buffer: IndexBuffer<u32>,
    pub normals: VertexBuffer<Normal>,
    pub uniform: LocalUniform
}

impl RenderObject {
    pub fn new(model: &Model, facade: &Facade) -> Self {
        Self {
            vertex_buffer: VertexBuffer::new(facade, &model.vertices).unwrap(),
            index_buffer: IndexBuffer::new(facade, PrimitiveType::TrianglesList, &model.indices).unwrap(),
            normals: VertexBuffer::new(facade, &model.normals).unwrap(),
            uniform: LocalUniform::new()
        }
    }

    pub fn rotate(&mut self, r: [f64; 3]) {
        let array_ptr = &self.uniform.transform;
        let mat_ptr: &Matrix4<f32> = unsafe { std::mem::transmute(array_ptr) };
        let rot = glm::ext::rotate(mat_ptr, 0.01, vec3(r[0] as f32, r[1] as f32, r[2] as f32));
        let rot_array: [[f32; 4]; 4] = unsafe { std::mem::transmute(rot) };
        self.uniform.transform = rot_array;

    }

    pub fn translate(&mut self, r: [f64; 3]) {
        let array_ptr = &self.uniform.transform;
        let mat_ptr: &Matrix4<f32> = unsafe { std::mem::transmute(array_ptr) };
        let trans = glm::ext::translate(mat_ptr, vec3(r[0] as f32, r[1] as f32, r[2] as f32));
        let trans_array = unsafe { std::mem::transmute::<Matrix4<f32>, [[f32; 4]; 4]>(trans) };
        self.uniform.transform = trans_array;
    }
}

#[derive(Copy, Clone, Debug)]
pub struct LocalUniform {
    pub transform: [[f32; 4]; 4]
}

impl LocalUniform {
    pub fn new() -> Self {
        Self { transform: [
            [ 1.0, 0.0, 0.0, 0.0 ],
            [ 0.0, 1.0, 0.0, 0.0 ],
            [ 0.0, 0.0, 1.0, 0.0 ],
            [ 0.0, 0.0, 0.0, 1.0 ],
        ]}
    }
}

impl Uniforms for LocalUniform {
    /// Calls the parameter once with the name and value of each uniform.
    fn visit_values<'a, F: FnMut(&str, UniformValue<'a>)>(&'a self, mut visitor: F) {
        visitor("transform", self.transform.as_uniform_value());
        visitor("u_light", [ -1.0, 0.4, 0.9f32 ].as_uniform_value());
    }
}

