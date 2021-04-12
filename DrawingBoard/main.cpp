#include <graphics.h>
#include "paintBoard.h"
#include "color.h"
#include "point.h"
#include "shape.h"

int main()
{
	PaintBoard pb;
	Line line;
	Circle circle;
	Rectangle_ rectangle;
	bool isFill = true;
	bool noFill = false;
	//�Ƿ��ȡ�Ĳ��֡�
	pb.clearFile(filePath);
	pb.initialize();
	pb.initGraph();
	pb.initText();
	while (true)
	{
		mouse_msg msg1 = getmouse();
		if (msg1.is_left() && msg1.is_down())//�ж��������Ƿ���
		{
			int x = msg1.x, y = msg1.y;
			if ((x <= 90 && x >= 10) && (y <= 200 && y >= 160))      //���ģ��
			{
				pb.clearPaint();
				//���tempfile.txt�б��������
				pb.clearFile(tempFilePath);
				pb.setGraphCount(0);
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				xyprintf(0, 510, "����ɹ���");
			}
			else if ((x <= 450 && x >= 370) && (y <= 200 && y >= 160))//�˳�ģ��
			{
				break; // ����whileѭ�����˳�����
			}
			else if ((x <= 80 && x >= 20) && (y <= 140 && y >= 80))   //��ֱ��ģ��
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				xyprintf(0, 510, "ѡ��ֱ�߳ɹ���");
				pb.deleteCancelGraph();
				pb.paintGraph(line, noFill);
				pb.writeToFile(line, tempFilePath);
			}
			else if ((x <= 150 && x >= 90) && (y <= 140 && y >= 80))   //�����ľ���ģ��
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				xyprintf(0, 510, "ѡ����ľ��γɹ���");
				pb.deleteCancelGraph();
				pb.paintGraph(rectangle, noFill);
				pb.writeToFile(rectangle, tempFilePath);
			}
			else if ((x <= 220 && x >= 160) && (y <= 140 && y >= 80))   //��������ģ��
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				xyprintf(0, 510, "ѡ�������γɹ���");
				pb.deleteCancelGraph();
				pb.paintGraph(rectangle, isFill);
				pb.writeToFile(rectangle, tempFilePath);
			}
			else if ((x <= 290 && x >= 230) && (y <= 140 && y >= 80))   //������Բģ��
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				xyprintf(0, 510, "ѡ�����Բ�ɹ���");
				pb.deleteCancelGraph();
				pb.paintGraph(circle, noFill);
				pb.writeToFile(circle, tempFilePath);
			}
			else if ((x <= 360 && x >= 300) && (y <= 140 && y >= 80))   //�����Բģ��
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				xyprintf(0, 510, "ѡ�����Բ�ɹ���");
				pb.deleteCancelGraph();
				pb.paintGraph(circle, isFill);
				pb.writeToFile(circle, tempFilePath);
			}
			else if ((x <= 40 && x >= 20) && (y <= 40 && y >= 20))       //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				pb.setGraphColor(colorset[0]);
				xyprintf(0, 510, "ѡ���ɫ�ɹ���");
			}
			else if ((x <= 65 && x >= 45) && (y <= 40 && y >= 20))       //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				pb.setGraphColor(colorset[1]);
				xyprintf(0, 510, "ѡ���ɫ�ɹ���");
			}
			else if ((x <= 90 && x >= 70) && (y <= 40 && y >= 20))       //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				pb.setGraphColor(colorset[2]);
				xyprintf(0, 510, "ѡ���ɫ�ɹ���");
			}
			else if ((x <= 115 && x >= 95) && (y <= 40 && y >= 20))      //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				pb.setGraphColor(colorset[3]);
				xyprintf(0, 510, "ѡ����ɫ�ɹ���");
			}
			else if ((x <= 140 && x >= 120) && (y <= 40 && y >= 20))      //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				pb.setGraphColor(colorset[4]);
				xyprintf(0, 510, "ѡ����ɫ�ɹ���");
			}
			else if ((x <= 165 && x >= 145) && (y <= 40 && y >= 20))      //����ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				pb.setGraphColor(colorset[5]);
				xyprintf(0, 510, "ѡ������ɫ�ɹ���");
			}
			else if ((x <= 190 && x >= 170) && (y <= 40 && y >= 20))      //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				pb.setGraphColor(colorset[6]);
				xyprintf(0, 510, "ѡ����ɫ�ɹ���");
			}
			else if ((x <= 215 && x >= 195) && (y <= 40 && y >= 20))      //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				pb.setGraphColor(colorset[7]);
				xyprintf(0, 510, "ѡ����ɫ�ɹ���");
			}
			else if ((x <= 240 && x >= 220) && (y <= 40 && y >= 20))      //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				pb.setGraphColor(colorset[8]);
				xyprintf(0, 510, "ѡ���ɫ�ɹ���");
			}
			else if ((x <= 40 && x >= 20) && (y <= 65 && y >= 45))        //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				pb.setGraphColor(colorset[9]);
				xyprintf(0, 510, "ѡ���ɫ�ɹ���");
			}
			else if ((x <= 65 && x >= 45) && (y <= 65 && y >= 45))        //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				pb.setGraphColor(colorset[10]);
				xyprintf(0, 510, "ѡ���ɫ�ɹ���");
			}
			else if ((x <= 90 && x >= 70) && (y <= 65 && y >= 45))        //ǳ��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				pb.setGraphColor(colorset[11]);
				xyprintf(0, 510, "ѡ��ǳ��ɫ�ɹ���");
			}
			else if ((x <= 115 && x >= 95) && (y <= 65 && y >= 45))       //���ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				pb.setGraphColor(colorset[12]);
				xyprintf(0, 510, "ѡ�����ɫ�ɹ���");
			}
			else if ((x <= 140 && x >= 120) && (y <= 65 && y >= 45))      //������ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				pb.setGraphColor(colorset[13]);
				xyprintf(0, 510, "ѡ������ɫ�ɹ���");
			}
			else if ((x <= 165 && x >= 145) && (y <= 65 && y >= 45))      //����ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				pb.setGraphColor(colorset[14]);
				xyprintf(0, 510, "ѡ������ɫ�ɹ���");
			}
			else if ((x <= 190 && x >= 170) && (y <= 65 && y >= 45))      //ǳ��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				pb.setGraphColor(colorset[15]);
				xyprintf(0, 510, "ѡ��ǳ��ɫ�ɹ���");
			}
			else if ((x <= 215 && x >= 195) && (y <= 65 && y >= 45))       //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				pb.setGraphColor(colorset[16]);
				xyprintf(0, 510, "ѡ����ɫ�ɹ���");
			}
			else if ((x <= 340 && x >= 300) && (y <= 65 && y >= 25))       //����
			{
				
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				if (pb.cancel())
					xyprintf(0, 510, "�����ɹ���");
			}
			else if ((x <= 390 && x >= 350) && (y <= 65 && y >= 25))       //��ԭ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				if (pb.restore())
					xyprintf(0, 510, "��ԭ�ɹ���");
			}
		}
	}
	pb.writeToFile();
	pb.clearFile(tempFilePath);
	closegraph();
	return 0;
}