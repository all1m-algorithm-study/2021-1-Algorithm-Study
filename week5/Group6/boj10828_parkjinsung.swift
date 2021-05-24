import Foundation
let n = Int(readLine()!)!
var arr: [Int] = []

for _ in 1...n {
  let order = readLine()!
  
  switch order {
  case "top":
    if arr == [] {
      print(-1)
    } else {
      print(arr[arr.count-1])
    }
  case "pop":
    if arr == [] {
      print(-1)
    } else {
      print(arr.popLast()!)
    }
  case "size":
    print(arr.count)
  case "empty":
    if arr == [] {
      print(1)
    } else {
      print(0)
    }
  default:
    let num = Int(order.components(separatedBy: " ")[1])!
    arr.append(num)
  }
}
