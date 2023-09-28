func isLucky(str string) bool {
	var num1 = str[0] + str[1] + str[2]
	var num2 = str[3] + str[4] + str[5]
	return (num1 == num2)
}
