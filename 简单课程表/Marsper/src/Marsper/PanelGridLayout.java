package Marsper;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
public class PanelGridLayout extends JPanel{
	/**
	 * 
	 */
	private static final long serialVersionUID = -5846560579867840524L;
	@SuppressWarnings("null")
	//int m;
	public PanelGridLayout() {
		GridLayout grid=new GridLayout(8,8);//���񲼾�
		//System.out.printf("%d",m);
		setLayout(grid);//�ղ���
		//add(new Button("����/����"));//GridLayout�еķ�������add����
		//add(new Button("����һ"));
		//add(new Button("���ڶ�"));
		//add(new Button("������"));
		//add(new Button("������"));
		//add(new Button("������"));
		//add(new Button("������"));
		//add(new Button("������"));
		Button button2=new Button();
		for (int i = 0; i<8; i++) {
			if(i>0) {//��λ��Ϊ(i,0)�������ı���i>0
				add(button2=new Button("��"+Integer.toString(i)+"���"));//Integer.toString(i)������iת�����ַ���
			}
			button2.setBackground(Color.WHITE);//����i,0���İ�ť����ɫ��ɰ�ɫ
			for (int j =0;j<7; j++) {
				if (i==0&&j==0) {//��λ��(0,0)�������ı�
					add(button2=new Button("����/����"));
				} 
				button2.setBackground(Color.WHITE);//����һ�еİ�ť����ɫ��ɰ�ɫ
				if (i==0&j==6) {//���Ͻ����������
					add(button2=new Button("������"));
					button2.setBackground(Color.WHITE);//�����Ͻǵİ�ť����ɫ��ɰ�ɫ
				}
				else if (i==0&(j>=0&j<6)) {//�ж��������1-6�����������7���������
					add(button2=new Button("����"+Integer.toString(j+1)));
				}
				else {
					Button button=new Button();
					add(button,BorderLayout.NORTH);//JButton�İ�ťΪ��ƽ�滯
					button.setBackground(Color.WHITE);//��ť����ɫ
					setForeground(Color.blue);//ǰ��ɫ
					setFont(new Font("����",Font.BOLD,16));//������ʽ
					button.addActionListener(new ActionListener() {//������ť
						@Override
						public void actionPerformed(ActionEvent e) {
							String str=JOptionPane.showInputDialog(button,"������γ���Ϣo(*�����*)o:","����Ի���",
							JOptionPane.PLAIN_MESSAGE);//��ÿ��Ҫд��γ̵İ�ť���öԻ���
							button.setLabel(str);
							//button2.setText(str);//���Ի�����������䵽��ť��
							/*if (str!=null) {  //�������
								System.out.println(str);
							} 
							else {
								System.out.println("��û����ѽ!");
							}*/	
						}
					});
				}
			}
		}
		
	}
}

