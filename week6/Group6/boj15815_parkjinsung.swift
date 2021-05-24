var stringArr = Array(readLine()!).map { String($0) }
var stack: [Int] = []

for temp in stringArr {
  switch temp {
  case "+":
    let a = stack.popLast()!
    let b = stack.popLast()!
    stack.append(b + a)
  case "-":
    let a = stack.popLast()!
    let b = stack.popLast()!
    stack.append(b - a)
  case "*":
    let a = stack.popLast()!
    let b = stack.popLast()!
    stack.append(b * a)
  case "/":
    let a = stack.popLast()!
    let b = stack.popLast()!
    stack.append(b / a)
  default:
    stack.append(Int(temp)!)
  }
}

print(stack[0])
