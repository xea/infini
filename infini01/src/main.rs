#[macro_use]
extern crate glium;

use engine::Engine;
use vertex::{Normal, Vertex};

mod engine;
mod model;
mod obj_loader;
mod render_object;
mod scene;
mod vertex;

fn main() {
    let mut engine = Engine::new();
    let model = engine.load_model("cube");

    engine.add_object(model);
    //engine.add_background();
    //engine.add_triangle();
    engine.attach_shader("default");
    engine.main_loop();
}
