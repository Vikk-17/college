// Develop and demonstrate a HTML file which includes JavaScript script,
// that uses functions for the following problems:
// a. Parameter: A string,
//     Output: The position in the string of the left most vowel
// b. Parameter: A number,
//     Output: The number with its digits in the reverse order

const vowels = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"];

function leftMostVowel() {
  const inp = document.getElementById("stringText").value;
  for (let i = 0; i < inp.length; i++) {
    for (let j = 0; j < 10; j++) {
      if (inp[i] == vowels[j])
        return (document.getElementById("vowelChar").innerText = `${
          inp[i]
        } with position ${i + 1}`);
      else continue;
    }
  }
  return (document.getElementById("vowelChar").innerHTML =
    "There is no vowel :(");
}

function reverseNumber() {
  let number = parseInt(document.getElementById("getNumber").value, 10);
  let rev = 0;
  if(isNaN(number)){
    return document.getElementById("revNumber").innerHTML = "Please enter a valid number"
  } else {
      while (number > 0) {
        let lastDigit = number % 10;
        number = Math.floor(number / 10);
        rev = rev * 10 + lastDigit;
      }
      return (document.getElementById(
        "revNumber"
      ).innerHTML = `The reverse number is ${rev}`);
  }
}
