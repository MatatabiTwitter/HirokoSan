#include <stdio.h>

void hiroko_ism(int *height) {
  if (*height < 180)
    *height = 180;
}

int main(void) {
  int count = 1;
  printf("�Ђ�q�u���Ȃ��̐g�������������Ă���낵���āH�v\n");
  while (1) {
    int height;
    printf("���Ȃ��͐����炩�ɋ��񂾁c�c�I: ");
    scanf("%d", &height);
    printf("���Ȃ��u���̐g���́c�c%d cm �����I�v\n", height);
    //*********************************
    // �Ђ�q����̖@���������c�c�I�I
    //*********************************
    hiroko_ism(&height);
    //*********************************
    fprintf(stdout, "�Ђ�q�u�܂��I %d cm ��������Ȃ̂ˁI�E���V�C���I�v\n\n", height);
    printf("�Ђ�q�u���āc�c%d �l�ڂ̂��Ȃ��A�g���͂������Ȃ̂�����H�v\n", ++count);
  }
}
