import Foundation

let n = Int(readLine()!)!
var deque: [Int] = []

for _ in 1...n {
  let order = readLine()!

  switch order {
  case "size":
    print(deque.count)
  case "empty":
    if deque.count == 0 {
      print(1)
    } else {
      print(0)
    }
  case "front":
    if deque == [] {
      print(-1)
    } else {
      print(deque.first!)
    }
  case "back":
    if deque == [] {
      print(-1)
    } else {
      print(deque.last!)
    }
  case "pop_front":
    if deque == [] {
      print(-1)
    } else {
      print(deque.removeFirst())
    }
  case "pop_back":
    if deque == [] {
      print(-1)
    } else {
      print(deque.removeLast())
    }
  default:
    let pushFrontStartIndex = order.index(order.startIndex, offsetBy: 10)
    let pushBackStartIndex = order.index(order.startIndex, offsetBy: 9)

    if order[order.startIndex..<pushFrontStartIndex] == "push_front" {
      let num = Int(order.components(separatedBy: " ")[1])!
      deque.reverse()
      deque.append(num)
      deque.reverse()
    } else if order[order.startIndex..<pushBackStartIndex] == "push_back" {
      let num = Int(order.components(separatedBy: " ")[1])!
      deque.append(num)
    }
  }
}
