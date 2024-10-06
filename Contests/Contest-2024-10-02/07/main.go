package main

import (
	"fmt"
	"strings"
	"io/ioutil"
	"strconv"
	"sort"
)

type pas struct {
	name string
	age int
}

//	просто какая-то жесть
func get_value(line *string) string {
	var value string
	quotes := false

	for _, v := range *line {
		if v == ',' && !quotes {
			break
		}
		if v == '"' {
			quotes = !quotes
		}
		value += string(v)
	}

	*line = strings.Replace(*line, value, "", 1)
	*line = strings.Replace(*line, ",", "", 1)

	if value == "" {
		value = "0"
	} else {
		if value[0] == '"' {
			value = value[1:]
			value = value[:len(value)-1]
			value = strings.Replace(value, "\"\"", "\"", -1)
		}
	}

	return value
}

func main () {
	var target_pclass int
	var target_age int
	passanger := make([]pas, 0)

	fmt.Scan(&target_pclass, &target_age)

	file_byte, _ := ioutil.ReadFile("train.csv")	//	запись байтовых значений файла
	file_data := string(file_byte)					//	конвертация байтов в символы
	lines := strings.Split(file_data, "\r")			//	разделение текста на строки

	for _, line := range lines {					//	итерирование по строкам
		_ = get_value(&line)								//	пропуск мусора
		_ = get_value(&line)								//	пропуск мусора
		pclass, _ := strconv.Atoi(get_value(&line))			//	класс
		name := get_value(&line)							//	имя
		sex := get_value(&line)								//	пол
		age, _ := strconv.Atoi(get_value(&line))			//	возраст
		
		if age > target_age && pclass == target_pclass && sex == "female" {
			var tmp_pas pas
			tmp_pas.name = name
			tmp_pas.age = age
			passanger = append(passanger, tmp_pas)
		}
	}

	sort.Slice(passanger, func(i, j int) bool {
		if passanger[i].age == passanger[j].age {
			return passanger[i].name < passanger[j].name
		}
    	return passanger[i].age < passanger[j].age
	})

	for _, v := range passanger {
		fmt.Print(v.name, "\n")
	}
}
