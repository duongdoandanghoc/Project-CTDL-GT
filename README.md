# Project CTDL & GT 
 # ***Bài toán quân mã cờ vua | Tìm đường đi ngắn nhất từ ​​nguồn đến đích***
![Bàn cờ vua](https://github.com/user-attachments/assets/f80eb4ed-c771-4da8-9c41-bd89b7469a16)

_Bàn cờ vua và các điểm trên bàn cờ vua_

****Mô tả giải thuật theo các bước phân tích sơ bộ:***

**Ý tưởng chính:*
1. Biểu diễn bàn cờ: Bàn cờ vua được biểu diễn dưới dạng một lưới 2D (vector 2 chiều) chứa các đối tượng KNIGHT. Mỗi ô trên bàn cờ chứa một đối tượng KNIGHT đại diện cho vị trí đó và lưu trữ các thông tin cần thiết như tọa độ, số bước từ nguồn (stips), danh sách các bước di chuyển hợp lệ (moves), và trạng thái đã kiểm tra (checked).
2. Di chuyển của quân mã: Quân mã trên bàn cờ vua có thể di chuyển theo hình chữ "L" (2 ô theo một hướng và 1 ô theo hướng vuông góc, hoặc ngược lại). Chương trình tạo danh sách tất cả các nước đi hợp lệ cho mỗi ô.
3. Tìm kiếm bằng thuật toán Breadth-First Search (BFS): Chương trình sử dụng BFS để tìm đường đi ngắn nhất từ vị trí bắt đầu đến vị trí kết thúc:

   -Khởi tạo: Tạo lưới các đối tượng KNIGHT và xác định vị trí bắt đầu và kết thúc.

   -Hàng đợi BFS: Một hàng đợi được khởi tạo với vị trí bắt đầu. Mỗi bước trong BFS sẽ lấy vị trí đầu hàng đợi (vị trí hiện tại), kiểm tra xem có phải là đích đến không, nếu không thì thêm các nước đi hợp lệ tiếp theo vào hàng đợi.

   -Ghi nhớ số bước: Mỗi bước di chuyển, chương trình ghi nhớ số bước di chuyển từ vị trí bắt đầu đến vị trí hiện tại bằng cách tăng giá trị stips từ vị trí trước đó.
5. Kết quả: Khi vị trí đích được tìm thấy, chương trình trả về số bước cần thiết để quân mã di chuyển từ vị trí bắt đầu đến vị trí kết thúc.


**Thuật toán chi tiết:*
- Khởi tạo lưới và hàng đợi BFS:
  
  +Tạo một lưới 8x8 của các đối tượng KNIGHT.
  
  +Xác định vị trí bắt đầu và kết thúc bằng cách giải mã chuỗi ký tự như "a1", "f7" thành tọa độ trên lưới.

- Duyệt BFS:
  
  +Lặp lại cho đến khi hàng đợi rỗng hoặc tìm thấy đích đến.
  
  +Lấy phần tử đầu tiên trong hàng đợi, đánh dấu là đã kiểm tra.
  
  +Thêm các nước đi hợp lệ của quân mã từ vị trí hiện tại vào hàng đợi nếu chưa được kiểm tra.
  
  +Cập nhật số bước cho mỗi vị trí mới.

- Kết thúc: Trả về số bước khi đích đến được tìm thấy.

![Ví dụ về các điểm quân mã có thể di chuyển](https://github.com/user-attachments/assets/1a0a1ca9-3d36-4b8d-b19e-49dc8b919b05)

_Một quân mã có thể di chuyển theo tám hướng có thể từ một ô nhất định, như minh họa trong hình trên_

   
****Mã giả (Pseudocode) phân tích giải thuật chi tiết:***
```cpp
class KNIGHT:
    // Thuộc tính của quân mã
    int stips   // Số bước di chuyển
    int row, col  // Vị trí hàng và cột trên bàn cờ
    KNIGHT *previous  // Trỏ đến vị trí trước đó
    list<KNIGHT *> moves  // Danh sách các nước đi hợp lệ
    bool checked  // Đánh dấu là kiểm tra chưa

    // Constructor khởi tạo
    function KNIGHT(i, j):
        row = i
        col = j
        previous = null
        checked = false

    // Tạo danh sách nước đi hợp lệ
    function nextMoves(grid):
        // Thêm các nước đi hợp lệ từ vị trí hiện tại vào danh sách moves

function include(queue, move, debut):
    // Kiểm tra xem nước đi đã có trong hàng đợi chưa
    for i từ debut đến hết queue:
        nếu move == queue[i]:
            return true
    return false

function decode(start, grid):
    // Chuyển chuỗi (ví dụ "a3") thành đối tượng KNIGHT trên lưới
    đảo ngược start
    row = 8 - số start   // Chuyển thành chỉ số hàng
    col = tìm vị trí của start[1] trong dãy 'a' đến 'h'
    return grid[row][col]

function knight(start, finish):
    // Khởi tạo bàn cờ 8x8 với KNIGHT
    tạo bàn cờ 8x8 với đối tượng KNIGHT

    end = decode(finish, grid)  // Lấy vị trí đích
    queue = [decode(start, grid)]  // Khởi tạo hàng đợi với vị trí bắt đầu

    debut = 0, fin = 1  // Đầu và cuối hàng đợi
    while debut < fin:
        current = queue[debut]
        debut++

        nếu current == end:  // Nếu đã đến đích
            break

        current.checked = true
        current.nextMoves(grid)  // Tạo danh sách nước đi hợp lệ

        // Duyệt các nước đi hợp lệ
        for move in current.moves:
            nếu move chưa được kiểm tra và không có trong queue:
                move.previous = current
                move.stips = current.stips + 1
                thêm move vào queue
                fin++

    return end.stips  // Trả về số bước di chuyển ít nhất

function main():
    // In ra số bước di chuyển ít nhất từ "a3" đến b5"
    in knight("a3", "b5")

```

****Bộ ví dụ bao gồm tập dữ liệu đầu vào và đầu ra theo giải thuật tương ứng:***
 
|       Nguồn       |      Điểm đến        | Đầu ra (Số bước tối thiểu cần thiết)     |
| :------------:|:-------------:|:-----:|
|    a3          |        b5      |  1    |
|     a1         |        f7      |   5   |
|     a1         | h8             |    6  |

![Chuyển động của quân mã từ a1 đến h8](https://github.com/user-attachments/assets/4e41d249-9be0-4c7c-a021-131bd8350586)

_Ví dụ về chuyển động của quân mã từ a1 đến h8_
