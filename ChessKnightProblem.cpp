#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Định nghĩa lớp KNIGHT đại diện cho vị trí của quân mã trên bàn cờ
class KNIGHT
{
public:
  int stips,              // Số bước di chuyển từ vị trí bắt đầu
      row, col;           // Vị trí hàng và cột trên bàn cờ
  KNIGHT *previous;       // Trỏ đến vị trí trước đó trong đường đi
  vector<KNIGHT *> moves; // Danh sách các nước đi hợp lệ từ vị trí hiện tại
  bool checked;           // Đánh dấu xem vị trí này đã được kiểm tra chưa

public:
  // Constructor khởi tạo với hàng và cột
  KNIGHT(int i, int j)
  {
    row = i;
    col = j;
    previous = nullptr;
    checked = false;
  }

  // Tạo danh sách các nước đi hợp lệ của quân mã từ vị trí hiện tại
  void nextMoves(vector<vector<KNIGHT *>> &grid)
  {
    if (col < 6)
    {
      if (row < 7)
      {
        // 1 bước xuống, 2 bước phải
        moves.push_back(grid[row + 1][col + 2]);
      }
      if (row > 0)
      {
        // 1 bước lên, 2 bước phải
        moves.push_back(grid[row - 1][col + 2]);
      }
    }

    if (col < 7)
    {
      if (row < 6)
      {
        // 2 bước xuống, 1 bước phải
        moves.push_back(grid[row + 2][col + 1]);
      }
      if (row > 1)
      {
        // 2 bước lên, 1 bước phải
        moves.push_back(grid[row - 2][col + 1]);
      }
    }

    if (col > 0)
    {
      if (row > 1)
      {
        // 2 bước lên, 1 bước trái
        moves.push_back(grid[row - 2][col - 1]);
      }
      if (row < 6)
      {
        // 2 bước xuống, 1 bước trái
        moves.push_back(grid[row + 2][col - 1]);
      }
    }

    if (col > 1)
    {
      if (row > 0)
      {
        // 1 bước lên, 2 bước trái
        moves.push_back(grid[row - 1][col - 2]);
      }
      if (row < 7)
      {
        // 1 bước xuống, 2 bước trái
        moves.push_back(grid[row + 1][col - 2]);
      }
    }
  }
};

