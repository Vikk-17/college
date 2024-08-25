function fib() {
  let n = prompt("Enter value of n");
  if (isNaN(n)) {
    alert("Please enter valid input");
  } else {
    let a = 0,
      b = 1,
      c = 0;
    let output = "Fibonacci Series\n";
    for (let i = 0; i < n; i++) {
      if (i == 0 || i == 1) {
        output += i + " ";
      }
      let c = a + b;
      output += c + " ";
      a = b;
      b = c;
    }
    alert(output);
  }
}

function square() {
  let n = prompt("Enter value of n");
  if (isNaN(n)) alert("Please enter a valid input");
  else {
    let output = "Number Sequence\n";
    for (let i = 1; i <= n; i++) {
      let sqr = i * i;
      output += i + "->" + sqr + "\n";
    }
    alert(output);
  }
}
