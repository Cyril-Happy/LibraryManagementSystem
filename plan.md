# 简介
 图书管理系统
# 需要实现的对象
## Menu类操作界面 
- 属性：
    - `adminLoggedIn`: **bool**，标记管理员是否已登录。
    - `adminManager`: **AdminManager** 对象，用于管理管理员功能。
- 方法：
    - `displayMainMenu()`：显示主菜单。
    - `login()`：管理员登录。
    - `logout()`：退出登录。
    - `run()`：系统的主循环，调用相关功能（图书管理、读者管理、借阅管理）。
## User 类
- 属性：
  - `user_id`: **long long**，用户编号。
  - `username`: **string**，用户名。
  - `password`: **string**，用户密码。
  - `role`: **string**，角色，值为 `"admin"` 或 `"reader"`。
- 方法：
  - `validateLogin()`: 验证用户登录信息。
  - `displayInfo()`: 显示用户信息（虚函数，可被子类重写）。
### 1.Admin 类（继承自 User）
- 属性
    - `admin_id`: **long long**，管理员编号。
    - `password`: **string**，管理员密码。
    - `username`: **string**，管理员用户名
- 方法
    - `validateLogin()`： 验证登录。
### 2.Reader 类（继承自 User）
- 属性：
  - 继承自 User。
- 方法：
  - 继承自 User。
  - `displayInfo()`: 显示读者详细信息。
  - `borrowBook()`: 借书。
  - `returnBook()`: 还书。

## Book 类
- 属性：
    - `book_id`: **long long**，图书编号。
    - `name`: **string**，书名。
    - `author`: **string**，作者。
    - `publish`: **string**，出版社。
    - `ISBN`: **string**，书籍编号。
    - `introduction`: **string**，简介。
    - `language`: **string**，语言。
    - `price`: **double**，价格。
    - `pub_date`: **string**，出版日期。
    - `class_id`: **int**，分类编号。
    - `number`: **int**，库存数量。
- 方法：
    - `displayInfo()`：显示书籍详细信息。

## 图书分类表 (class_info)
- 属性
    - `class_id`: int (Primary Key)
    - `class_name`: varchar
- 方法
    - `display()`：显示分类信息。

## AdminManager 类
负责管理员功能的实现，包括图书管理、读者管理、借还管理等。
- 属性：
    - `bookManager`: **BookManager** 对象，用于管理图书。
    - `readerManager`: **ReaderManager** 对象，用于管理读者。
    - `lendManager`: **LendManager** 对象，用于管理借还记录。
- 方法：
    - `addBook()`：添加图书。
    - `deleteBook()`：删除图书。
    - `searchBooks()`：模糊/精准搜索图书。
    - `printBooks()`：打印所有图书信息。
    - `addReader()`：添加读者。
    - `deleteReader()`：删除读者。
    - `searchReaders()`：模糊/精准搜索读者。
    - `printReaders()`：打印所有读者信息。
    - `viewLogs()`：查看借还日志。

## Manager 类的设计
### 1.BookManager 类
负责图书管理相关操作。
- 属性：`vector<Book>`。
- 方法：
  - `addBook()`：添加图书。
  - `deleteBook()`：删除图书。
  - `searchBooks()`：模糊或精准查找图书。
  - `printBooks()`：打印所有图书信息。

### 2.ReaderManager 类
负责读者管理相关操作。
- 属性：`vector<ReaderInfo>` 和 `vector<ReaderCard>`。
- 方法：
  - `addReader()`：添加读者。
  - `deleteReader()`：删除读者。
  - `searchReaders()`：模糊或精准查找读者。
  - `printReaders()`：打印所有读者信息。

### 3.LendManager 类
负责借阅管理相关操作。
- 属性：`vector<LendList>`。
- 方法：
  - `addLend()`：记录借阅信息。
  - `returnBook()`：记录还书信息。
  - `viewLogs()`：打印借还日志。

## 可选功能
### 1.借阅信息表 (lend_list)
- 属性
    - `ser_num`: **long long**，流水号。
    - `book_id`: **long long**，图书编号。
    - `reader_id`: **long long**，读者编号。
    - `lend_date`: **string**，借书日期。
    - `back_date`: **string**，还书日期。
- 方法
    - `display()`：显示借阅记录。

### 2.借阅卡信息表 (reader_card)
- `reader_id`: bigint (Primary Key)
- `password`: varchar
- `username`: varchar

### 3.读者信息表 (reader_info)
- 属性
    - `reader_id`: bigint (Primary Key)
    - `name`: varchar
    - `sex`: varchar
    - `birth`: date
    - `address`: varchar
    - `phone`: varchar
- 方法：
    - `display()`：显示读者详细信息。

