#include <stdio.h>

void hiroko_ism(int *height) {
  __asm {
      mov ebx, height
      mov eax, [ebx]
      cmp eax, 180
      jb normal
      cmp eax, 114514
      jne end
    abnormal:
      mov eax, 889464
      mov [ebx], eax
      jmp end
    normal:
      mov eax, 180
      mov [ebx], eax
    end:
  }
}

char hirokosan_no_arigatai_okotoba[] = "ひろ子「あなたの身長をお聞きしてもよろしくて？」\n";
char anata_no_shout[] = "あなたは声高らかに叫んだ……！: ";
char format[] = "%d";
char todoke_kono_omoi[] = "あなた「俺の身長は %d cm だぜ！」\n";
char hirokosan_is_rule[] = "ひろ子「まぁ！ %d cm もおありなのね！ウレシイワ！」\n\n";
char next_sacrifice[] = "ひろ子「さて……%d 人目のあなた、身長はおいくつなのかしら？」\n";

void main() {
  int height;
  int count = 1;
  __asm {
      //ひろ子さんの有難いお言葉
      push offset hirokosan_no_arigatai_okotoba
      call printf
      pop eax
    hiroko_loop:
      //身長おいくつ？
      push offset anata_no_shout
      call printf
      pop eax
      //あなたは入力する……
      lea eax, [height]
      push eax
      push offset format
      call scanf
      pop eax
      pop eax
      //俺の身長はぁぁっ！
      push height
      push offset todoke_kono_omoi
      call printf
      pop eax
      pop eax
      //＿人人人人人人人人人人人人人人人人人人人人人人人＿
      //＞ ひろ子さんの法則がアセンブラで乱れる……！！ ＜
      //￣Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^￣
      lea eax, [height]
      push eax
      call hiroko_ism
      pop eax
      //*********************************************
      //ここから ひろ子ワールド
      //*********************************************
      push height
      push offset hirokosan_is_rule
      call printf
      pop eax
      pop eax
      //*********************************************
      //ひろ子ワールド ここまで
      //*********************************************
      //100人斬りへのカウント（到達したからといって何もない）
      mov eax, count
      add eax, 1
      mov count, eax
      //はい、次のお客様
      push count
      push offset next_sacrifice
      call printf
      pop eax
      pop eax
      jmp hiroko_loop
  }
}
