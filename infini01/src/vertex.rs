type VertexCoord = f64;

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

/// Defines a normal vector of a given vertex
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
