# 코딩 테스트를 위한 동적계획 수련법

## 동적계획 수련을 위한 문제: 삼각형 위의 최대 경로 찾기

문제에 대한 설명 및 온라인 저지 문제는 알고스팟과 프로젝트 오일러 참조:
https://www.algospot.com/judge/problem/read/TRIANGLEPATH
https://www.algospot.com/judge/problem/read/TRIPATHCNT
https://projecteuler.net/problem=18
https://projecteuler.net/problem=67

먼저, 위의 문제들을 충분한 시간을 두고 스스로 생각해서 한 번 풀어보세요.
처음 보는 문제라면 3~4일 정도 풀어 보는 것이 적당하고,
이미 풀어본 문제라 하더라도 하루 정도는 스스로 다양한 방법을 시도해 보세요.

그렇게 스스로 충분히 생각해 본 이후에 본 수련법을 따라가면 큰 도움이 됩니다.

## 단계별로 문제 풀어보기

1. 재귀를 이용해서 분할정복으로 문제 풀기
2. 메모이제이션으로 분할정복의 중복 부분 문제 해결하기
3. 최적값을 얻기 위한 동적계획법 적용하기
4. 최적값과 함께 최적해를 얻도록 동적계획법 확장하기
5. 최적값을 가진 최적해의 개수를 얻도록 추가로 확장하기
6. 최적해의 개수를 얻는 방법도 동적계획법으로 풀기
7. 최적값, 최적해의 개수, 최적해를 모두 한꺼번에 얻기

## 수련을 마치고 나서 더 해볼 수 있는 것들

1. 최적해를 순서대로 나열했을 때, k번째 최적해만 출력하라고 하면?
2. 최대 경로가 아니라, 최단 경로라면 백트래킹으로 구할 수 있지 않을까?
3. 백트래킹을 적용할 수 있다면, 분기한정을 적용하면 더 효율적이지 않을까?

백트래킹: Backtracking = Depth-First-Search with Pruning (using promising function)
분기한정: Branch-and-Bound = Best-Breadth-First-Search with Pruning
