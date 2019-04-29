/// Defines a single vertex with x, y, z coordinates
#[derive(Copy, Clone, Debug)]
pub struct Vertex {
    pub position: [f64; 3]
}

impl Vertex {
    pub fn new(x: f64, y: f64, z: f64) -> Self {
        Self { position: [ x, y, z ] }
    }
}

implement_vertex!(Vertex, position);

/// Defines a normal vector of a given vertex
#[derive(Copy, Clone, Debug)]
pub struct Normal {
    pub normal: [f64; 3]
}

impl Normal {
    pub fn new(x: f64, y: f64, z: f64) -> Self {
        Self { normal: [ x, y, z ] }
    }
}

implement_vertex!(Normal, normal);
