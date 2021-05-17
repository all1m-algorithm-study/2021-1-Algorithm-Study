import Foundation
let n = Int(readLine()!)!
var queue: [Int] = []

for _ in 1...n {
  let order = readLine()!
  
  switch order {
  case "front":
    if queue == [] {
      print(-1)
    } else {
      print(queue.first!)
    }
  case "back":
    if queue == [] {
      print(-1)
    } else {
      print(queue.last!)
    }
  case "size":
    print(queue.count)
  case "empty":
    if queue == [] {
      print(1)
    } else {
      print(0)
    }
  case "pop":
    if queue == [] {
      print(-1)
    } else {
      print(queue.removeFirst())
    }
  default:
    let num = Int(order.components(separatedBy: " ")[1])!
    queue.append(num)
  }
}
