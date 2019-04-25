use crate::render_object::RenderObject;

pub struct Scene {
    nodes: Vec<Node>
}

pub enum Node {
    Group(Vec<Node>),
    Single(RenderObject)
}

