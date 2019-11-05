# 버튼 게임
## 풀이
### 풀이에 사용된 개념
#### 최대공약수 (Greatest Common Divisor, GCD)


#### 유클리드 호제법


### 아이디어
주어진 알파벳과 숫자의 대응은 아스키코드와 같다!  
정수로 받아 `char`에 저장하고 문자로 프린트하면 된다.  

### 코드
#### C
```C
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main() {
    int a, b, n, swap = FALSE;
    
    scanf("%d %d", &a, &b);
    scanf("%d", &n);
    
    //Without Loss of Generality
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
        
        swap = TRUE;
    }
    
    int r = n % b;
    int q = 0;
    for (int i = 0; i < b; ++i) {
        if ((a * i) % b == r) {
            q = i;
            break;
        }
    }
    
    int x = q;
    int y = (n - a * q) / b;
    
    if (swap == TRUE) {
        printf("%d %d", y, x);
        return 0;
    }
    
    printf("%d %d", x, y);
}
```

코드의 저작권은 전상완(Sangwan Jeon, maxswjeon@naver.com)에게 있습니다.  