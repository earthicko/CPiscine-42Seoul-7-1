`2022-04-25 donghyle`

# 개요

**The N-Queen Problem**

체스판에 퀸이 서로를 공격할 수 없도록 10개 배치하는 문제이다.
퀸은 상하좌우/좌상/우상/좌하/우하 방향으로 공격이 가능하므로 어차피 같은 행에 퀸이 2개 이상 존재할 수 없다. 따라서 퀸을 무조건 0열부터 9열까지 순서대로 배치해도 로직은 변하지 않는다. 0열부터 9열까지 차례대로 가능한 모든 행에 퀸을 배치해보면 된다.

# 정의

## 함수 정의

다음의 함수를 구현한다.

* 임의의 체스판 상태를 입력으로 받아
    * 상태를 보아하니 모든 열을 다 채운 상태라면 성공 시 해야 할 일을 하고 종료한다.
    * 아직 모든 열을 채우지 못했다면
        * 지정된 열에 퀸을 배치하려고 시도한다.
            * 0행부터 9행까지 차례대로 이 칸에 퀸을 배치할 수 있는지 (배치해도 공격당하지 않는 상황인지) 판단한다.
                * 배치할 수 없다면 다음 행으로 넘어간다.
                * 배치할 수 있다면 배치하고, 체스판 상황도 그에 맞게 업데이트한다.
                * 다음 열에 퀸을 배치하는 함수를 호출한다.
                * 위 호출이 끝난 후, 방금 배치한 칸에서 퀸을 없앤다. 체스판 상황도 그에 맞게 업데이트한다.
                * 다음 행으로 넘어간다.

## 상태 배열 정의

### 개요

체스판의 *상태*는 배열을 이용하여 기록해 놓으면 편하다.

예를 들어, i번째 행에 퀸이 배치되어 있는지 확인하고 싶을 때에는 다음의 방식을 활용해 볼 수 있다.
```
0번 행부터 9번 행까지 순차적으로 확인하면서 만약 n번 행에 퀸이 있을 시 참, 9행까지 확인이 끝난 경우 거짓을 반환한다.
```
이 방식은 예외가 없는 훌륭한 알고리즘이지만 체스판의 상태를 수천번 확인해봐야 하는 현재 상황에서는
다소 느린 방법일 수도 있다. 매번 퀸을 놓기 전마다 상-하방향 칸 10개, 좌-우방향 칸 10개, 대각 방향 칸 최대 20개를 확인해야 하기 때문이다.

따라서 매번 칸을 확인하기보다 체스판의 현황을 기록하는 참/거짓 배열을 만든 후, 체스판의 상태에 변화가 생길때마다 현황판을 갱신하면 될 것이다. 현황판이 항상 최신 상태로 유지된다면 n번 행에 퀸이 있는지 확인하고 싶을 때 현황판의 n번 칸에 참이 써 있는지 거짓이 써 있는지 확인하면 된다.

```
체 스 판 상 황 도

행별 퀸 배치 현황
[0]		[1]		[2]		[3]		[4]		[5]		[6]		[7]		[8]		[9]		
있음	없음	없음	있음	없음	있음	있음	없음	없음	없음
```

단 한번의 시선으로 자신이 공격받을 것인지 확인할 수 있다. 공간을 희생하여 시간을 번 것이다.
이 문제에서 체스판을 조작하는 유일한 주체는 우리다. 따라서 우리가 퀸을 놓거나 뺄 때마다 빠짐없이 현황판을 갱신해준다면 현황판의 내용은 항상 참이다.

### 대각 방향 공격

임의의 행에 퀸이 있음을 기록하는 배열을 만드는 것은 자명한 일이다. n개의 행이 있다면 n개의 원소를 가진 배열을 만들고, n번 원소를 참조하면 된다.

하지만 퀸은 대각 방향으로 공격이 가능하기 때문에 이에 대한 현황판도 정의해야 하는데, 대각 방향 칸들은 번호를 붙이는 방법을 새로 규정해줘야 한다.

```
(0, 0)*		(0, 1)		(0, 2)		...		(0, n-1)
(1, 0)		(1, 1)*		(1, 2)		...		(1, n-1)
(2, 0)		(2, 1)		(2, 2)*		...		(2, n-1)
...			...			...			...		...		
(n-1, 0)	(n-1, 1)	(n-1, 2)	...		(n-1, n-1)*
```

위 좌표계에서 별표(*) 표시한 칸들의 공통점은 행-열 좌표값의 차가 0으로 같다는 점이다.

```
(0, 0)		(0, 1)		(0, 2)*		...		(0, n-1)
(1, 0)		(1, 1)*		(1, 2)		...		(1, n-1)
(2, 0)*		(2, 1)		(2, 2)		...		(2, n-1)
...			...			...			...		...		
(n-1, 0)	(n-1, 1)	(n-1, 2)	...		(n-1, n-1)
```

같은 원리로 위에서 별표 표시한 칸들은 좌표의 합이 2로 같다.

따라서 좌상/우하단으로 공격 가능한 칸들의 묶음이 체스판에 총 `2n - 1`개 존재하고, 이들의 번호는 `행 - 열`의 값으로 구할 수 있다. 좌하/우상단으로 공격 가능한 칸의 번호는 `행 + 열`이다. 이때 `행 - 열`의 값은 `-(n - 1) ~ (n - 1)`이므로 모든 번호를 0 이상으로 만들기 위해 전체적으로 `(n - 1)`을 더해준다.

최종적으로 필요한 현황판 배열은 다음 3종류이다.

* 같은 행에 퀸이 있음을 기록하는 배열 `in_row[x]`

```
x =	0	0	0	0	0	0	0	0	0	0	
x =	1	1	1	1	1	1	1	1	1	1	
x =	2	2	2	2	2	2	2	2	2	2
x =	3	3	3	3	3	3	3	3	3	3
x =	...	...	...	...	...	...	...	...	...	...	
x =	9	9	9	9	9	9	9	9	9	9

x =	i_row
```

* 좌상/우하단 대각 방향에 퀸이 있음을 기록하는 배열 `in_upleft[x]`

```
x =	9	8	7	6	5	4	3	2	1	0
x =	10	9	8	7	6	5	4	3	2	1
x =	11 	10	9	8	7	6	5	4	3	2
x =	12	11	10	9	8	7	6	5	4	3
x =	...	...	...	...	...	...	...	...	...	...	
x =	9	8	7	6	5	4	3	2	1	0

x = i_col - i_row + 9
```

* 우상단 대각 방향에 퀸이 있음을 기록하는 배열 `in_upright[x]`

```
x =	0	1	2	3	4	5	6	7	8	9
x =	1	2	3	4	5	6	7	8	9	10
x =	2	3	4	5	6	7	8	9	10	11
x =	3	4	5	6	7	8	9	10	11	12
x =	...	...	...	...	...	...	...	...	...	...	
x =	9	1	11	12	13	14	15	16	17	18

x = i_col + i_row
```

# 구현 세부 사항

* 모든 성공 사례를 출력하고 모든 성공 사례의 개수를 반환해야 한다. 따라서 성공 사례를 발견 할 때마다 해당 상태를 출력하고 별도로 마련해 놓은 카운터를 증가시킨다.
* Norm때문에 3개의 현황판 배열을 함수에 모두 인자로 전달하는 것은 힘들다. 각각의 원소 번호에 배열 크기 만큼의 오프셋을 지정하여 하나의 배열에 모두 기록할 수 있다.
* 퀸의 유무를 기록하는 현황판만 필요한 것이 아니라 퀸이 *몇 번* 행에 있는지 기록하는 배열 또한 필요하다.

최종적으로 주 함수의 프로토타입은 다음과 같이 도출된다.

`퀸 놓아보기 (놓아볼 열 번호, 여태까지 퀸을 놓은 행 번호, 체스판 현황판, 카운터)`

`2022-04-25 donghyle`