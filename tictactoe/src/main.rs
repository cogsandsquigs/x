use crate::game::Board;

mod game;

fn main() {
    let b = Board::new();

    println!("{b}");
}
