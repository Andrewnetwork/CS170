/*
This class keeps track of which puzzles the user has solved. Also, provides the interface to 
the puzzles.In addition, the functions will return a 0 or 1 indicitive of wether or not the
player solved the puzzle. 

Number of puzzles: 10.

Function types: Type int. X-ZY: X = 0 for not solving puzzle, X = 1 for solving the puzzle.
ZY = number of puzzle, range- 01 - 10. 

*/

class puzzles
{
	public:
		//Place the function prototypes of the puzzles here. 
		puzzles();
		int puzzle1();

	private:
		bool isSolvedArray[10];
		void solvedPuzzle();



};

puzzles::puzzles()
{
}
