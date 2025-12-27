---
marp: true
paginate: true
# title: AAA史山代码批发
# backgroundImage: url('https://nixos.org/_astro/nixos-logo-default-gradient-black-regular-horizontal-none.BPpok6mb_JppMK.svg')
---

# OI 与 C++ 与你：逃离文化课的实用方法

PS: 大部分 `cp` from OI-Wiki

Powered by [Marp](https://marp.app/)

---

写的比较大便，请谅解

---

## Contents

* [OI](#一oi)
  * [概念](#1-概念)
  * [赛制](#2-赛制)
  * [测评系统](#3-测评系统)
* [C++](#二c基础语法)
  * [关键字](#1-关键字)
  * [一些语法糖 & 小技巧](#2-一些语法糖小技巧)
* [Good Luck & Have Fun](#gl--hf)

---

## 一、OI

相信大家都知道了，所以就讲的简略一点.png

---

### (1) 概念

详见 [OI-Wiki/OI 赛事与赛制](https://oi-wiki.org/contest/oi/)。

OI，全称**信息学奥林匹克竞赛**（Olympiad in Informatics），是一门在中学生中广泛开展的学科竞赛，与数学、物理、化学、生物并称五大学科竞赛。OI 考察的内容是参赛者运用算法、数据结构和数学知识，通过编写计算机程序解决实际问题的能力。

对于大部分中国选手而言，每年的新赛季从 9 月的 CSP-J/S 第一轮开始。

---

### (2) 赛制

OI 赛制：每位选手每一题只能提交一次，赛事无法看到评测结果。每道题都有多个测试点，根据每道题通过的测试点的数量获得相应的分数；每个测试点还可能会有部分分，即使只有部分数据通过也能拿到分数。  
代表性的比赛：CSP-J/S 第二轮、NOIP、省选、NOI。

IOI 赛制：选手在比赛时有多次提交机会。比赛实时评测并返回结果，如果提交的结果是错误的，不会有任何惩罚。每道题都有多个测试点，根据每道题通过的测试点的数量获得相应的分数。  
代表性的比赛：APIO、IOI

还有一些其他赛制，比如 Codeforces, ICPC, 乐多, etc.，这里就不展开了。

---

### (3) 测评系统

主流的测评系统有

* NOI Linux 内置的 Arbiter（但是难用的一批，除了比赛的时候不建议用）
* [LemonLime](https://github.com/Project-LemonLime/Project_LemonLime)
* [CCR-Plus](https://github.com/sxyzccr/CCR-Plus)（绍一前辈用 Qt 写的，拜谢\o/）（虽然已经不再维护了）

---

然后应该就没别的可说的了……
更加详细的介绍，可以看看[这个](slide.pdf)
比赛之外的，大家可以看看[这个](OI%20杂谈.pdf)

---

## 二、C++基础语法

相信大家也知道了，但是我还是要讲.gif

---

C++ 是一门经典的高级语言，作为 CCF 指定比赛用语言。

了解 C++ 基础语法对打比赛是非常有必要的

---

### (1) 关键字

以下是 C++ 14 下的关键字列表（按字典序排序）：

```cpp
alignas alignof and and_eq asm auto
bitand bitor bool break
case catch char char16_t char32_t class compl concept const constexpr const_cast continue
decltype default delete do double dynamic_cast
else enum explicit export extern
false float for friend
goto
if inline int
long
mutable
namespace new noexcept not not_eq nullptr
operator or or_eq
private protected public
register reinterpret_cast return
short signed sizeof static static_assert static_cast struct switch
template this thread_local throw true try typedef typeid typename
union unsigned using
virtual void volatile
wchar_t while
xor xor_eq
```

---

### (2) 一些语法糖&小技巧

1\. 自动推导类型

```cpp
int i = 0;
auto j = i + 1; // j 是 int
// 看起来没啥用？下面的呢
std::vector<int> vector;
auto iter = vector.begin();
// 等价于
// std::vector<int>::iterator iter = vector.begin();
```

---

2\. 基于范围的 for 循环

```cpp
std::queue<int> queue;
for (int i : queue) { // i 是 queue 中的元素
  // do something with i
  std::cout << i << ' ';
}
// queue = { 1, 2, 3, 4, 5 };
// 输出：1 2 3 4 5
```

---

3\. 输出一行的数据

```cpp
std::vector<int> ans;
for (const int &x : ans) {
  std::cout << x << " \n"[&x == &ans.back()]; // 等价于 (&x == &ans.back() ? '\n' : ' ')
}
```

把 `ans` 的内容输出，用空格分隔，最后输出换行（~~适合强迫症~~）

---

4\. 加速 `cin` `cout`

```cpp
std::cin.tie(nullptr)->sync_with_stdio(false);
```

`std::cin.tie(nullptr)`：把 `cin` 绑定到空指针，即与 `cout` 解绑，返回 `std::ostream *`
`std::ostream::sync_with_stdio(false);`：关闭 `iostream` 和 `<cstdio>` 之间的同步流

等价于

```cpp
std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
// 或者 std::ios_base::sync_with_stdio
```

~~但是看起来更高级~~

---

以下是一段经典的缺省源：（PS: 缺省源，顾名思义，缺省的源代码）

---

```cpp
#include <iostream>
#include <vector>

namespace W1ngD1nGa5ter {

class Process {
public:
  int operator()() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x : a) {
      std::cin >> x;
    }
    return 0;
  }
};

} // namespace W1ngD1nGa5ter

int main() {
  if (std::freopen("filename.in", "r", stdin) == nullptr ||
      std::freopen("filename.out", "w", stdout) == nullptr) {
    return 1;
  }
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int _T{1};
  // std::cin >> _T;
  while (_T--) {
    int ret = W1ngD1nGa5ter::Process{}();
    if (ret)
      return ret;
  }
  std::cout << std::flush;
  return 0;
}
```

---

看不懂？看不懂就对了，我的码风广受诟病（）

这里有几个 ~~如何写出别人抄都不想抄的代码的~~ 建议：

* 不要再写 `#include <bits/stdc++.h>` 了！
  理由：会导入大量不需要的符号，导致冲突的可能性增加（如著名的 `<cmath>` 中的 `y1`），还会严重拖慢编译时间；只有 GCC 能用，POJ之类的地方没法使用
* 不要再全局写 `using namespace std;` 了！
  理由：会把大量 std 里的东西引入全局，导致冲突
* （不卡常的情况下）不要再定义宏了！
  理由：宏超脱于代码，导致大量难以预知和调试的问题，如 `<windows.h>` 中有 `min` `max` 宏，导致你写 `std::max(a, b)` 会 CE，编译器给出的报错信息也会把宏展开，不直观，增加调试难度，应当使用 `inline` 函数和 `constexpr` 编译期常量代替

---

* 建议把代码包进自己的 `namespace`
  理由：这样你可以写 `y1` 了，而且零开销
* 建议多测扔进临时对象里
  理由：多测不清空，亲人两行泪，扔进对象里 RAII 会自动帮你清空，不必手动干预
  警告：卡常时不要这么写

---

学习的好地方：

* [哔哩哔哩](https://www.bilibili.com/video/BV1GJ411x7h7)
* [OI-Wiki](https://oi-wiki.org/?q=OI+Wiki)
* [洛谷](https://www.luogu.com.cn/user/3)
* [代码力量](https://codeforces.com)
* [AtCoder](https://atcoder.jp)
* [LibreOJ](https://loj.ac)
* [水滴OJ](https://hydro.ac)
* [OIer Db](https://oier.baoshuo.dev)

---

## GL & HF

㊗️各位高中生涯愉快！
