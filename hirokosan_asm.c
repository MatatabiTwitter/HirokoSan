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

char hirokosan_no_arigatai_okotoba[] = "�Ђ�q�u���Ȃ��̐g�������������Ă���낵���āH�v\n";
char anata_no_shout[] = "���Ȃ��͐����炩�ɋ��񂾁c�c�I: ";
char format[] = "%d";
char todoke_kono_omoi[] = "���Ȃ��u���̐g���� %d cm �����I�v\n";
char hirokosan_is_rule[] = "�Ђ�q�u�܂��I %d cm ��������Ȃ̂ˁI�E���V�C���I�v\n\n";
char next_sacrifice[] = "�Ђ�q�u���āc�c%d �l�ڂ̂��Ȃ��A�g���͂������Ȃ̂�����H�v\n";

void main() {
  int height;
  int count = 1;
  __asm {
      //�Ђ�q����̗L������t
      push offset hirokosan_no_arigatai_okotoba
      call printf
      pop eax
    hiroko_loop:
      //�g���������H
      push offset anata_no_shout
      call printf
      pop eax
      //���Ȃ��͓��͂���c�c
      lea eax, [height]
      push eax
      push offset format
      call scanf
      pop eax
      pop eax
      //���̐g���͂������I
      push height
      push offset todoke_kono_omoi
      call printf
      pop eax
      pop eax
      //�Q�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�Q
      //�� �Ђ�q����̖@�����A�Z���u���ŗ����c�c�I�I ��
      //�PY^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^�P
      lea eax, [height]
      push eax
      call hiroko_ism
      pop eax
      //*********************************************
      //�������� �Ђ�q���[���h
      //*********************************************
      push height
      push offset hirokosan_is_rule
      call printf
      pop eax
      pop eax
      //*********************************************
      //�Ђ�q���[���h �����܂�
      //*********************************************
      //100�l�a��ւ̃J�E���g�i���B��������Ƃ����ĉ����Ȃ��j
      mov eax, count
      add eax, 1
      mov count, eax
      //�͂��A���̂��q�l
      push count
      push offset next_sacrifice
      call printf
      pop eax
      pop eax
      jmp hiroko_loop
  }
}
