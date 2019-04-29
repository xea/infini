use crate::render_object::RenderObject;

pub struct Scene {
    nodes: Vec<Node>
}

impl Scene {
    pub fn new(nodes: Vec<Node>) -> Self {
        Self { nodes }
    }
}

pub enum Node {
    Group(Vec<Node>),
    Single(RenderObject)
}

