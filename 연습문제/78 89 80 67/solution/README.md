# 78 89 80 67
## 풀이
### 풀이에 사용된 개념
#### 아스키코드
아스키코드란 미국 ANSI에서 표준화한 정보교환용 7비트 부호체계이다. 000(0x00)부터 127(0x7F)까지 총128개 부호가 사용된다. 코드표는 다음과 같다.  

![아스키코드표](./solution/img/ASCII-Table.png)

#### C언어 형식 문자열
C언어의 printf 함수와 scanf함수에서 사용되는 형식 문자열은 다음과 같다.

![형식문자열](./solution/img/C-Type-String.png)

### 아이디어
주어진 알파벳과 숫자의 대응은 아스키코드와 같다!  
정수로 받아 `char`에 저장하고 문자로 프린트하면 된다.  

### 코드
#### C
```C
#include <stdio.h>

int main() {
    int count;
    scanf("%d", &count);
    
    for (int i = 0; i < count; ++i) {
        int temp;
        scanf("%d", &temp);
        printf("%c ", temp);
    }

    return 0;
}
```

코드의 저작권은 전상완(Sangwan Jeon, maxswjeon@naver.com)에게 있습니다.  