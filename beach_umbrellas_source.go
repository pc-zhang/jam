// Author:	PengchengZhang
// Date:	2016/11/4

package main

import (
	"flag"
	"fmt"
	"io/ioutil"
	"math"
	"math/big"
	"sort"
	"strconv"
	"strings"
)

func check(err error) {
	if err != nil {
		panic(err)
	}
}

func C(N int, points int) int {
	y := big.NewInt(1)
	for i := points + 1; i <= points+N; i++ {
		I := big.NewInt(int64(i))
		y.Mul(y, I)
	}

	for i := 1; i <= N; i++ {
		I := big.NewInt(int64(i))
		y.Div(y, I)
	}

	d := big.NewInt(1000000007)

	return int(y.Mod(y, d).Uint64())
}

func compute(Rs []int, M int) string {
	g := make(map[int]int)
	sort.Ints(Rs)
	N := len(Rs)
	if N == 1 {
		return fmt.Sprintf("%d", M%1000000007)
	}
	sum := 0
	for _, v := range Rs {
		sum += v
	}
	kmax := 2*sum + 1 - Rs[0] - Rs[1]
	kmin := 2*sum + 1 - Rs[N-1] - Rs[N-2]
	if M < kmin {
		return fmt.Sprintf("%d", 0)
	}
	y := 1
	for i := 1; i <= N-2; i++ {
		y *= i
		y %= 1000000007
	}
	for i, r1 := range Rs {
		for j, r2 := range Rs {
			if i != j {
				g[2*sum+1-r1-r2] += y
				g[2*sum+1-r1-r2] %= 1000000007
			}
		}
	}
	sum = 0

	for key, val := range g {
		if key <= M {
			sum += val * C(N, M-key) % 1000000007
		}
	}

	return fmt.Sprintf("%d", sum%1000000007)
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
		Rs := make([]int, 0)
		for i := 1; i <= N; i++ {
			r, err := strconv.Atoi(lines[i])
			check(err)
			Rs = append(Rs, r)
		}

		fmt.Printf("Case #%d: %s\n", caseNum, compute(Rs, M))
		lines = lines[N+1:]
	}
}
