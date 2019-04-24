use super::{Vertex};
use crate::engine::Normal;

pub struct Model {
    pub vertices: Vec<Vertex>,
    pub indices: Vec<u32>,
    pub normals: Vec<Normal>
}

impl Model {
    pub fn new(vertices: Vec<Vertex>, indices: Vec<u32>, normals: Vec<Normal>) -> Self {
        Self { vertices, indices, normals }
    }
}

