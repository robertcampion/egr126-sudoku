#pragma once

#include <array>
#include <utility>

using std::array;

//Declaration of class.
class Board {
	//Declaration of variables.
public:
	static constexpr int box_size = 3;
	static constexpr int size = box_size * box_size;
	static constexpr int max_index = size * size;
private:
	array<int, size * size> numbers;

	//Declaration of functions
public:
	Board();

	int get(int index) const;
	int get(int row, int col) const;
	int get_box(int box, int box_idx) const;
	
	void set(int index, int value);
	void set(int row, int col, int value);
	void set_box(int box, int box_idx, int value);

	bool solved() const;
	
	static Board random();

private:
	static int row_col_to_index(int row, int col);
	static std::pair<int, int> index_to_row_col(int index);

	static int box_number_to_index(int box, int box_idx);
	static std::pair<int, int> index_to_box_number(int index);

	int solution_count(int i = 0, int count = 0);
	bool fill_board(int i = 0);

};