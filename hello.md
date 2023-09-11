# hello.git

## git summary of command

- clone: copy from remote repository
- add: file add on stage area
- commit: save, save file from stage area.
- push: upload to remote repository
- 한글 테스트

## 브랜치 변경하기

- 브랜치란: 기존 내용을 유지한 상태에서 새로운 내용을 추가하고 싶을 때 사용한다.
- 체크아웃: 특정 브랜치(혹은 커밋)으로 돌아가고 싶을 때 사용한다.
- 소스트리의 체크아웃: 브랜치 이름을 더블 클릭하는 것만으로 체크아웃 가능.

## 병합하기1
- 헤드 브랜치에 변경사항이 없고
- 병합 대상 브랜치가 헤드로부터 시작된 경우
- 아주 쉽게 병합 가능 = fast-forward

## 병합하기2
- 헤드 브랜치가 추가적인 커밋이 생기는 경우
- 진짜 병합이 필요해 진다.
- 충돌이 안 나면 좋은데, 충돌이 나도 겁내지 말자.

## 커밋 되돌리기

### reset

- 쉽지만 커밋이 날아간다
- 강제 푸시가 필요하다