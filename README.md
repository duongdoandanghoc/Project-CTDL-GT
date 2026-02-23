# Thuật Toán Tìm Đường Đi Quân Mã (Chess Knight Problem) 🐎

[![C++](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=c%2B%2B)](https://isocpp.org/)
[![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)](https://github.com/duongdoandanghoc/Project-CTDL-GT)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](LICENSE)

## 🌟 Giới thiệu

Dự án này giải quyết bài toán **Tìm đường đi ngắn nhất cho quân mã trên bàn cờ vua (8x8)**. Sử dụng thuật toán **Tìm kiếm theo chiều rộng (BFS - Breadth-First Search)**, chương trình đảm bảo tìm ra số bước tối ưu nhất từ một vị trí nguồn đến đích bất kỳ.

![Bàn cờ vua](https://github.com/user-attachments/assets/f80eb4ed-c771-4da8-9c41-bd89b7469a16)
*Bàn cờ vua và các tọa độ chuẩn*

## ✨ Tính năng nổi bật

*   **Tối ưu hóa đường đi:** Luôn tìm ra số bước di chuyển ít nhất nhờ đặc tính của BFS trên đồ thị không trọng số.
*   **Hệ thống tọa độ chuẩn:** Chấp nhận đầu vào theo ký hiệu bàn cờ vua tiêu chuẩn (ví dụ: `a1`, `h8`).
*   **Mô hình hóa OOP:** Sử dụng lớp `KNIGHT` để quản lý trạng thái, vị trí và danh sách nước đi.
*   **Minh họa trực quan:** Mã nguồn đi kèm với các phân tích giải thuật và mã giả chi tiết.

## 🧠 Phân tích giải thuật

### Ý tưởng chính
1.  **Biểu diễn bàn cờ:** Bàn cờ được mô hình hóa dưới dạng lưới 2D của các đối tượng `KNIGHT`. Mỗi đối tượng lưu trữ tọa độ, số bước từ nguồn (`stips`), và trạng thái đã duyệt (`checked`).
2.  **Luật di chuyển:** Quân mã di chuyển theo hình chữ "L" (8 hướng có thể).
3.  **Chiến lược BFS:** Sử dụng hàng đợi (Queue) để duyệt qua các ô. Ô nào được tìm thấy đầu tiên chính là đường đi ngắn nhất.

![Ví dụ về các điểm quân mã có thể di chuyển](https://github.com/user-attachments/assets/1a0a1ca9-3d36-4b8d-b19e-49dc8b919b05)
*Các hướng di chuyển hợp lệ của quân mã*

### 📊 Bảng ví dụ thực tế

| Nguồn | Đích | Số bước tối thiểu |
| :---: | :---: | :---: |
| **a3** | **b5** | **1** |
| **a1** | **f7** | **5** |
| **a1** | **h8** | **6** |

![Chuyển động của quân mã từ a1 đến h8](https://github.com/user-attachments/assets/4e41d249-9be0-4c7c-a021-131bd8350586)
*Minh họa hành trình từ a1 đến h8 (6 bước)*

## 📁 Cấu trúc dự án

```
Project-CTDL-GT/
├── ChessKnightProblem.cpp  # ⚙️ Mã nguồn C++ chính
├── ChessKnightProblem.exe  # 🚀 Tệp thực thi (Windows)
├── README.md               # 📖 Tài liệu hướng dẫn sử dụng
└── ...
```

## 🛠️ Hướng dẫn cài đặt & Sử dụng

<details>
<summary><b>1. Biên dịch từ mã nguồn</b></summary>

Yêu cầu trình biên dịch C++ (g++, clang, hoặc MSVC).
```bash
g++ ChessKnightProblem.cpp -o ChessKnightProblem
```
</details>

<details>
<summary><b>2. Chạy chương trình</b></summary>

```bash
./ChessKnightProblem
```
Mặc định chương trình sẽ tính toán khoảng cách từ `a3` đến `b5`. Bạn có thể thay đổi tham số trong hàm `main()` của tệp `.cpp`.
</details>

<details>
<summary><b>3. Xem mã giả (Pseudocode)</b></summary>

```cpp
function knight(start, finish):
    tạo bàn cờ 8x8 với đối tượng KNIGHT
    end = decode(finish, grid)
    queue = [decode(start, grid)]
    
    while queue không rỗng:
        current = queue.pop()
        nếu current == end: break
        
        current.checked = true
        for move in current.nextMoves():
            nếu move chưa checked:
                move.stips = current.stips + 1
                queue.push(move)
                
    return end.stips
```
</details>

---

## 🌍 English Summary

### **Chess Knight Shortest Path Solver**

This repository provides a C++ implementation to solve the **Knight's Shortest Path** problem on a standard 8x8 chessboard using the **Breadth-First Search (BFS)** algorithm.

**Key Highlights:**
*   **Guaranteed Optimality:** Finds the minimum moves required using BFS traversal.
*   **Algebraic Notation:** Supports standard chess coordinates like "a1" or "h8".
*   **Object-Oriented:** Clean design with a `KNIGHT` class to manage board states.
*   **Educational:** Includes detailed pseudocode and visual diagrams for learning purposes.

**Quick Start:** Compile with `g++ ChessKnightProblem.cpp -o solver` and run the executable to see the algorithm in action.

---

## 🤝 Đóng góp

Mọi ý tưởng cải tiến (ví dụ: thêm giao diện đồ họa, tối ưu bộ nhớ) đều được hoan nghênh. Vui lòng tạo **Issue** hoặc **Pull Request**.

## 📄 Giấy phép

Dự án này được phát hành dưới Giấy phép MIT.

---

*Tài liệu này được nâng cấp bởi **Manus AI** vào ngày 23 tháng 2 năm 2026.*

*Liên hệ tác giả: [duongdoandanghoc](https://github.com/duongdoandanghoc)*
