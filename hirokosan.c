#include <stdio.h>

void hiroko_ism(int *height) {
  if (*height < 180)
    *height = 180;
}

int main(void) {
  int count = 1;
  printf("ひろ子「あなたの身長をお聞きしてもよろしくて？」\n");
  while (1) {
    int height;
    printf("あなたは声高らかに叫んだ……！: ");
    scanf("%d", &height);
    printf("あなた「俺の身長は……%d cm だぜ！」\n", height);
    //*********************************
    // ひろ子さんの法則が乱れる……！！
    //*********************************
    hiroko_ism(&height);
    //*********************************
    fprintf(stdout, "ひろ子「まぁ！ %d cm もおありなのね！ウレシイワ！」\n\n", height);
    printf("ひろ子「さて……%d 人目のあなた、身長はおいくつなのかしら？」\n", ++count);
  }
}
