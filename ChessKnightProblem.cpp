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

// Hàm kiểm tra xem nước đi có trong hàng đợi không
bool include(vector<KNIGHT *> &queue, KNIGHT *move, const int &debut)
{
  for (int i = debut; i < queue.size(); i++)
  {
    if (move == queue[i])
    {
      return true;
    }
  }
  return false;
}

// Hàm chuyển đổi chuỗi vị trí (ví dụ "a1") thành vị trí của KNIGHT trên lưới
KNIGHT *decode(string start, vector<vector<KNIGHT *>> &grid)
{
  reverse(start.begin(), start.end());
  int row = 8 - stoi(start); // Chuyển đổi số thành chỉ số hàng
  char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
  int col;
  for (int i = 0; i < 8; i++)
  {
    if (start[1] == alpha[i])
    {
      col = i;
    }
  }
  return grid[row][col];
}

// Hàm chính tìm số bước di chuyển ít nhất của quân mã từ vị trí bắt đầu đến vị trí kết thúc
int knight(std::string start, std::string finish)
{
  // Tạo lưới bàn cờ 8x8 với các đối tượng KNIGHT
  vector<vector<KNIGHT *>> grid(8, vector<KNIGHT *>(8));
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      grid[i][j] = new KNIGHT(i, j);
    }
  }

  // Lấy vị trí đích
  KNIGHT *end = decode(finish, grid);
  // Khởi tạo hàng đợi BFS với vị trí bắt đầu
  vector<KNIGHT *> queue = {decode(start, grid)};

  KNIGHT *current;
  int debut = 0, fin = 1; // Vị trí đầu và cuối của hàng đợi
  while (debut < fin)
  {
    current = queue[debut];
    debut++;

    // Nếu tìm thấy vị trí đích, kết thúc
    if (current == end)
    {
      break;
    }
    current->checked = true;
    current->nextMoves(grid); // Điền danh sách nước đi hợp lệ từ vị trí hiện tại

    // Duyệt qua các nước đi hợp lệ
    for (int i = 0; i < current->moves.size(); i++)
    {
      if (!current->moves[i]->checked && !include(queue, current->moves[i], debut))
      {
        current->moves[i]->previous = current;
        current->moves[i]->stips = current->stips + 1;
        queue.push_back(current->moves[i]);
        fin++;
      }
    }
  }

  return end->stips; // Trả về số bước cần di chuyển ít nhất
}

int main()
{
  // In ra số bước di chuyển ít nhất của quân mã từ ô "a3" đến ô "b5" trên bàn cờ vua
  cout << knight("a3", "b5");
}
