## 1. 배열(Array)란?
- 연관된 데이터를 하나의 변수에 그룹핑해서 관리하기 위한 방법

## 2. 연결 리스트(Linked List)
- 노드(node)와 링크(link)를 구조화 시킨 것
- 종류
    1. 단일 연결 리스트
    2. 양방향 연결 리스트
    3. 원형 연결 리스트

## 3. 배열(Array) vs 연결 리스트(Linked List)

||Array|Linked List|
|:------:|:---:|:---:|
|크기|정적(static)|동적(dynamic)|
|주소|순차적|랜덤|

## 4. 시간 복잡도(Time Complexity 👉 Big O)

1. 접근 속도
    - 배열: 인덱스를 통한 탐색 👉 O(1)
    - 연결 리스트: 순차적으로 탐색 👉 O(n)

2. 삽입 속도
    - 배열
        - 삽입하려고 하는 데이터가 맨 뒤가 아닐 때 👉 O(n)
        - 맨 뒤 + 배열에 공간이 남아있다면 👉 O(1)
    - 연결 리스트
        - 삽입하려고 하는 데이터가 맨 앞 👉 O(1)
        - 그 이후라면 👉 O(n)
3. 삭제 속도
    - 배열
        - 삭제하려는 데이터의 위치가 맨 뒤가 아니라면 👉 O(n)
        - 삭제하려는 데이터의 위치가 맨 뒤 + 그 배열에 공간이 남아 있다면 👉 O(1)
    - 연결 리스트
        - 삭제하려는 하는 데이터의 위치가 맨 앞 👉 O(1)
        - 삭제하려는 데이터의 위치가 맨 앞 그 이후 👉 O(n)

✅ 데이터의 접근, 탐색 👉 배열 > 연결 리스트
✅ 데이터의 추가, 삭제 👉 배열 < 연결 리스트

## 5. 참고 자료
- <a href="https://opentutorials.org/module/1335/8677">생활 코딩_배열</a>
- <a href="https://www.youtube.com/watch?v=NFETSCJON2M">노마드코더_배열</a>
- <a href="https://opentutorials.org/module/1335/8636">생활 코딩_리스트</a>
- <a href="youtube.com/watch?v=BEVnxbxBqi8&t=18s">시간복잡도란?</a>
- <a href="https://m.blog.naver.com/raylee00/221944085465">배열과 리스트의 시간 복잡도</a>