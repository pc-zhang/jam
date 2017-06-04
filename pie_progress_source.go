// Author:	PengchengZhang
// Date:	2016/11/4
// https://www.facebook.com/hackercup/scoreboard/1825579961046099

package main

import (
	"flag"
	"fmt"
	"io/ioutil"
	"math"
	"sort"
	"strconv"
	"strings"
)

func check(err error) {
	if err != nil {
		panic(err)
	}
}

func mymin(a int, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func f(i int, store int, N int, M int, C [][]int, memory map[string]int) int {
	if check, ok := memory[fmt.Sprintf("%d,%d", i, store)]; ok {
		return check
	}

	if N-i-store == 0 {
		memory[fmt.Sprintf("%d,%d", i, store)] = 0
		return memory[fmt.Sprintf("%d,%d", i, store)]
	}

	memory[fmt.Sprintf("%d,%d", i, store)] = math.MaxInt32
	if store == 0 {
		for p := 1; p <= mymin(N-i-store, M); p++ {
			sum := 0
			for j := 0; j < p; j++ {
				sum += C[i][j]
			}
			sum += p*p + f(i+1, store+p-1, N, M, C, memory)
			if sum < memory[fmt.Sprintf("%d,%d", i, store)] {
				memory[fmt.Sprintf("%d,%d", i, store)] = sum
			}
		}
	} else {
		for p := 0; p <= mymin(N-i-store, M); p++ {
			sum := 0
			for j := 0; j < p; j++ {
				sum += C[i][j]
			}
			sum += p*p + f(i+1, store+p-1, N, M, C, memory)
			if sum < memory[fmt.Sprintf("%d,%d", i, store)] {
				memory[fmt.Sprintf("%d,%d", i, store)] = sum
			}
		}
	}

	return memory[fmt.Sprintf("%d,%d", i, store)]
}

func compute(N int, M int, C [][]int) string {
	memory := make(map[string]int)

	return fmt.Sprintf("%d", f(0, 0, N, M, C, memory))
}

func main() {
	var input = flag.String("i", "", "Required")
	flag.Parse()

	content, err := ioutil.ReadFile(*input)
	check(err)

	lines := strings.Split(string(content), "\n")

	numOfTests, err := strconv.Atoi(lines[0])
	check(err)

	lines = lines[1:]

	for caseNum := 1; caseNum <= numOfTests; caseNum++ {
		hs := strings.Split(lines[0], " ")
		N, err := strconv.Atoi(hs[0])
		check(err)
		M, err := strconv.Atoi(hs[1])
		check(err)
		C := make([][]int, N)
		for i := 1; i <= N; i++ {
			ss := strings.Split(lines[i], " ")
			ps := make([]int, M)
			for j, val := range ss {
				price, err := strconv.Atoi(val)
				check(err)
				ps[j] = price
				C[i-1] = ps
			}
			sort.Ints(ps)
		}

		fmt.Printf("Case #%d: %s\n", caseNum, compute(N, M, C))
		lines = lines[N+1:]
	}
}
