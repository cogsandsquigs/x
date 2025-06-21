use core::fmt;

/// The possible states of a cell in the Tic Tac Toe game.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Player {
    /// None cell, not occupied by any player.
    None,

    /// A cell occupied by player X.
    X,

    /// A cell occupied by player O.
    O,
}

/// A board for a Tic Tac Toe game.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct Board {
    /// The cells of the board, indexed from 0 to 8.
    /// Starting from the top-left corner and moving left to right, then top to bottom.
    cells: [Player; 9],
}

impl Board {
    /// Creates a new board with all cells empty.
    pub fn new() -> Self {
        Board {
            cells: [Player::None; 9],
        }
    }

    /// Sets the state of a cell at the given index.
    pub fn set_cell(&mut self, across: usize, down: usize, state: Player) {
        debug_assert!(across < 3 && down < 3, "Index out of bounds");
        self.cells[across + down * 3] = state;
    }

    /// Gets the state of a cell at the given index.
    pub fn get_cell(&self, across: usize, down: usize) -> &Player {
        debug_assert!(across < 3 && down < 3, "Index out of bounds");
        &self.cells[across + down * 3]
    }

    /// Gets the empty cells of the board. Returns a vector of tuples where each tuple contains
    /// `(<across>, <down>)` coordinates of the empty cells. See `Board.cells` for the indexing
    /// scheme.
    pub fn get_empty_cells(&self) -> Vec<(usize, usize)> {
        let mut empty_cells = Vec::new();

        for (index, &cell) in self.cells.iter().enumerate() {
            if cell == Player::None {
                let across = index % 3;
                let down = index / 3;
                empty_cells.push((across, down));
            }
        }

        empty_cells
    }

    /// Check if someone has won the game. Returns `CellsState::X` if player X has won,
    /// `CellsState::O` if player O has won, and `CellsState::None` if no one has won yet.
    pub fn did_win(&self) -> Player {
        // Check rows
        for row in 0..3 {
            if self.cells[row * 3] != Player::None
                && self.cells[row * 3] == self.cells[row * 3 + 1]
                && self.cells[row * 3] == self.cells[row * 3 + 2]
            {
                return self.cells[3 * row];
            }
        }

        // Check columns
        for col in 0..3 {
            if self.cells[col] != Player::None
                && self.cells[col] == self.cells[col + 3]
                && self.cells[col] == self.cells[col + 6]
            {
                return self.cells[col];
            }
        }

        // Check diagonals
        if self.cells[0] != Player::None
            && self.cells[0] == self.cells[4]
            && self.cells[0] == self.cells[8]
        {
            return self.cells[0];
        }

        if self.cells[2] != Player::None
            && self.cells[2] == self.cells[4]
            && self.cells[2] == self.cells[6]
        {
            return self.cells[2];
        }

        Player::None
    }
}

impl fmt::Display for Board {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        for row in 0..3 {
            write!(f, " ")?;

            for col in 0..3 {
                let cell = self.get_cell(col, row);
                let symbol = match cell {
                    Player::None => ' ',
                    Player::X => 'X',
                    Player::O => 'O',
                };
                write!(f, "{} {}", symbol, if col < 2 { "| " } else { "" })?;
            }

            if row < 2 {
                writeln!(f, "\n---+---+---")?;
            } else {
                writeln!(f)?;
            }
        }
        Ok(())
    }
}
