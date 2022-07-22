# RUSH 01
재미있는 스도쿠 놀이

# 개요

## board.h
* board 구조체 정의
* 함수 prototype 정의

## main.c
* OS와 소통
* `argc`, `argv`를 받아와 적절치 못한 값일 경우 에러 핸들링
* `solver` 호출
* `solver`의 결과를 확인하여 해가 존재할 경우 출력, 불가능할 경우 에러 핸들링

## board.c
* board 객체 생성
* board에 관한 메소드 정의
    * up/down/left/right에 대한 view 검증
    * 임의의 좌표에 value 지정 가능한지 여부 확인
    * 왼쪽 위부터 빈 칸을 탐색하여 가장 먼저 출현하는 빈 칸의 좌표 확인 및 반환
* board 객체 출력

## solver.c
* 재귀 기반 문제 해결 알고리즘

# board.h

board 구조체 정의

```
int     size            // 격자의 가로/세로 크기
int     **height        // 격자에 적힌 숫자 상태 (생성자에 의해 동적 할당됨)
                        // height[row][col] -> row행 col열에 적힌 숫자
int     *up_view        // 위에서 보았을 때 보여야 하는 박스의 개수
int     *down_view      // 아래에서 ~
int     *left_view      // 왼쪽에서 ~
int     *right_view     // 오른쪽에서 ~
int     **in_row        // 특정 행에 특정 숫자가 이미 쓰여 있는지 여부 저장
                        // in_row[x][h] == 1 -> x번 행에 높이 h의 박스가 이미 존재한다.
                        // in_row[x][h] == 0 -> x번 행에 높이 h의 박스는 없다. (그러므로 넣어도 된다.)
int     **in_col        // 특정 열에 ~
```

# main.c

## 역할

각 함수 호출 및 에러 핸들링

## 의사 코드

### 함수 목록
* `int    main(int argc, char **argv)`
    * `argc` 가 적절하지 않을 시 종료
    * `argv` 문자열을 `board` 생성자에 넘겨 `board` 구조체 획득
        * 생성에 실패하였을 경우 (valid하지 않은 argv일 경우) 에러 핸들링
    * `solver`에 `board` 구조체 전달
        * 해가 존재할 경우 출력
        * 해가 존재하지 않을 경우 에러 핸들링
    * OS에 프로그램이 종료되었음을 알림

# board.c

## 역할

`board` 객체의 다양한 속성 및 동작을 정의

## 의사 코드

### 함수 목록
* `t_board *create_board(char *views)`: view 정보를 담은 문자열을 파싱, 불가능할 시 `NULL` 을 반환하라.
    * view 문자열 내에 출현하는 숫자의 개수는 `4의 배수` 여야 함.
    * `숫자의 개수 / 4`가 board의 가로/세로 크기임.
    * 모든 숫자는 board의 크기보다 작거나 같아야 함.

    * 위 조건을 모두 만족할 시:
        * `board->size` 지정
        * `board->height`에 2차원 배열 동적할당 후 `0`으로 초기화
        * `views`를 파싱하여 `board->up_view, down_view, left_view, right_view`에 채워넣음
        * `board->in_row, in_col`을 `0`으로 초기화

* `int is_col_valid(t_board *this, int i_col)`: i_col번 열이 view를 만족하는가?
    * 해당 열에서 출현한 최대의 box height를 의미하는 `max_height = 0` 준비
    * 해당 열에서 보이는 박스 개수를 의미하는 `views = 0` 준비
    * `[0, this->size)`의 i_row에 대하여:
        * `this->height[i_row][i_col]`이 `max_height`보다 크면:
            * `views++`: 박스가 1개 더 보인다.
            * `max_height`를 height와 비교하여 최댓값 갱신: 이제부터 이 높이보다 작거나 같은 박스는 보이지 않는다.
    * 이 시점에서 `views`의 크기가 `this->up_view[i_col]`과 다르다면 이 column은 valid하지 않다.

    * 위 과정을 `(this->size, 0]`의 i_row와 `this->down_view[i_col]`을 가지고 반복한다.

    * 두 테스트를 모두 통과했다면 이 column은 valid하다.

* `int is_row_valid(t_board *this, int i_row)`: i_row번 열이 view를 만족하는가?
    * `is_col_valid`의 논리를 열이 아닌 행에 대하여 수행한다.

* `int is_duplicate(t_borad *this, int i_row, int i_col, int h)`: i_row행 i_col열에 h를 적어도 중복이 발생하지 않는가?
    * `this->in_row[i_row][h] == 1`이면 중복이다.
    * `this->in_col[i_col][h] == 1`이면 중복이다.
    * 두 테스트를 모두 통과했다면 중복은 없다.

* `int search_empty_grid(t_board *this, int *o_row, int *o_col)`: 왼쪽 위부터 좌횡서 방향으로 빈 칸을 탐색하여 가장 먼저 출현하는 빈 칸의 좌표를 `o_row`, `o_col`에 저장한다.
    * 반복문 사용

* `void set_height_at(t_board *this, int i_row, int i_col, int h)`: board의 i_row행 i_col열에 높이 h를 적는다. 이때 validity 및 duplicity는 확인하지 않는다.
    * `h_prev = this->height[i_row][i_col]`: 해당 위치에 적혀있던 값을 `h_prev`에 저장
    * `h_prev`가 0 (초기값)이 아니라면:
        * `this->in_row[i_row][h_prev] = 0`
        * `this->in_col[i_col][h_prev] = 0` : 해당 행/열에서 `h_prev`의 높이를 가진 박스가 사라졌음을 기록
    * `this->in_row[i_row][h] = 1`
    * `this->in_col[i_col][h] = 1`: 해당 행/열에 이제부터는 `h`의 높이를 가진 박스가 존재함을 기록
    * `this->height[i_row][i_col] = h`: 해당 위치에 숫자를 적는다

* `void print_board(t_board *this)`: board의 높이 정보를 문제에서 정의한 서식대로 출력한다.

# solver.c

## 역할

문제 해결

## 의사 코드

### 함수 목록

* `int solve(t_board *this)`: 임의의 상태를 가진 `board`를 넘겨받아 맨 앞의 빈 칸에 가능한 수를 모두 넣어보고 가능한 경우가 있을 시 참, 없을 시 거짓을 반환한다.

    * board에 빈 칸이 남아있다면 빈 칸 중 가장 왼쪽 위에 있는 i_row, i_col (`search_empty_grid` 함수를 호출하면 구할 수 있다)에 대해: 
        * `[1, this->size)` 범위 내의 `h`에 대해:

            * `(i_row, i_col)` 좌표에 `h`를 적을 수 있다면 (`is_duplicate`로 확인 가능):
                * `(i_row, i_col)` 좌표에 `h`를 적어본다. (`set_height_at`으로 수행 가능)
                * i_row가 마지막 값인데 `is_row_valid`이 거짓이라면:
                    * 다음 `h`로 스킵한다.
                * i_col이 마지막 값인데 `is_col_valid`이 거짓이라면:
                    * 다음 `h`로 스킵한다.

                * (위 테스트 2개를 모두 통과했다면 `h`를 `(i_row, i_col)`에 적어도 된다.)
                * `solve(this)`를 다시 호출한다.
                    * 반환값이 참이라면 (쭉 적어 내려간 결과 가능한 해가 발견됨) 참을 반환
                    * 반환값이 거짓이라면 (쭉 적어 내려가던 도중에 절대 불가능한 경우임이 증명됨):
                        * 다음 `h`로 스킵한다.
        * `[1, this->size)` 범위 내에서 가능한 `h`가 발견되지 않았을 경우:
            `(i_row, i_col)` 좌표에 다시 `0`을 적고 0을 반환한다.
            
    * (빈 칸이 남아있지 않다면 모든 칸이 채워졌고 모두 valid함이 증명되었으므로) 참을 반환한다.

