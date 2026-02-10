package main
import "fmt"

func main(){
	var num1 int = 10;
	fmt.Println("Initial : ", num1);

	var num2 = 20;
	fmt.Println(num2);

	num1 = 20;
	fmt.Println("final: ", num1);

	num3 := 30;
	fmt.Println(num3);
}