package Marsper;
import java.awt.*;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.text.SimpleDateFormat;
import java.util.*;
import javax.swing.*;
public class ShowLayout extends JFrame{
	/**
	 * 
	 */
	private static final long serialVersionUID = 6138822567962823251L;
	//������
	PanelGridLayout pannelGrid;//���
	JTabbedPane p;//ѡ�����
	/*JMenuBar bar; //�˵���
	JMenu menu;//�˵�
	JMenuItem item;//�˵��� */
	JMenuBar menuBar;//�˵���
	JMenu menu,subMenu;//�˵�
	JMenuItem item1,item2,exit;//�˵���
	public ShowLayout() {	
		/*bar = new JMenuBar();
		menu = new JMenu("�ļ�");
		item = new JMenuItem("�½�");
		menu.add(item);
		bar.add(menu);
		this.setJMenuBar(bar);*/
		menuBar=new JMenuBar();//�˵���
		menu=new JMenu("�˵�");//�˵�
		item1=new JMenuItem("�½�",new ImageIcon("D:/eclipse workspace/Marsper/bin/Marsper/3 (2).png"));
		item2=new JMenuItem("�˻�����",new ImageIcon("D:/eclipse workspace/Marsper/bin/Marsper/3 (1).png"));
		subMenu=new JMenu("�л�����");//�˵���
		exit=new JMenuItem("�˳�",new ImageIcon("D:/eclipse workspace/Marsper/bin/Marsper/3 (6).png"));//�˵���
		item1.setAccelerator(KeyStroke.getKeyStroke('N'));
		item2.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S,InputEvent.CTRL_MASK));
		exit.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_W,InputEvent.CTRL_MASK));
		menu.add(item1);
		menu.addSeparator();
		menu.add(item2);
		menu.add(subMenu);
		menu.add(exit);
		// JMenuItem sonMenuItem = new JMenuItem("��ƽ",new ImageIcon("D:/eclipse workspace/Marsper/bin/Marsper/3 (7).png"));// �����Ӳ˵���������Ĳ˵���
	      JMenuItem sonMenuItem1=new JMenuItem("����",new ImageIcon("D:/eclipse workspace/Marsper/bin/Marsper/3 (4).png"));// �����Ӳ˵������ƽ�Ĳ˵���
	      sonMenuItem1.setAccelerator(KeyStroke.getKeyStroke('L'));
	      subMenu.add(sonMenuItem1);
		//subMenu.add(sonMenuItem);
		menuBar.add(menu);
		setJMenuBar(menuBar);
		pannelGrid=new PanelGridLayout();
		p=new JTabbedPane();
		p.add("Marsper",pannelGrid);
		add(p,BorderLayout.CENTER);
		JButton buttontime=new JButton();
		add(buttontime,BorderLayout.SOUTH);//�ڴ��ڵײ����һ����ť������ʾʱ��
		buttontime.setBackground(Color.WHITE);//ʱ�䰴ťΪ��ɫ
		 /*Calendar date = Calendar.getInstance();
		 buttontime.setLabel(Calendar.getInstance().getTime().toString()); �������ں�ʱ��*/
		 SimpleDateFormat df = new SimpleDateFormat("yyyy��MM��dd��  EEEE  HH:mm");//�������ں�ʱ��
		 buttontime.setText("(��������)����"+df.format(new Date()));//�ڰ�ť����ʾ���ں�ʱ��
		 buttontime.setFont(new Font("����",Font.BOLD,20));//������ʽ
		 buttontime.setPreferredSize(new Dimension(40,40));//��ť��С
		 buttontime.setContentAreaFilled(true);//��ť�Ƿ�͸�� falseΪ͸��
		 buttontime.setBorderPainted(true);//��ť�Ƿ�ȥ���߿� falseΪȥ��
		//buttontime.setBorder(BorderFactory.createRaisedBevelBorder());//����ť��Ϊͻ��״
		 //buttontime.setBorder(BorderFactory.createLoweredBevelBorder());//����ť��Ϊ����״
		 item1.addActionListener(new ActionListener() {//������ť
				@Override
				public void actionPerformed(ActionEvent e) {
					String str=JOptionPane.showInputDialog(item1,"�������ָı�γ̱�����,n�ڿ�,����n-5(��:��6�ڿ�,������1):","����Ի���o(*�����*)o",
					JOptionPane.PLAIN_MESSAGE);//��ÿ��Ҫд��γ̵İ�ť���öԻ���
					//int m=Integer.parseInt(str);
						//	new GridLayout(6+m,8);
						//new PanelGridLayout();
					//System.out.printf("%d",6+Integer.parseInt(str));
				}
			});
		 item2.addActionListener(new ActionListener() {//������ť,������¼��ť
				@Override
				public void actionPerformed(ActionEvent e) {
					new denglu();
				}
			});
		 exit.addActionListener(new ActionListener() {//������ť,�����˳���ť
				@Override
				public void actionPerformed(ActionEvent e) {
					System.exit(0);//�˳���ǰ����	
				}
			});
		 /*sonMenuItem.addActionListener(new ActionListener() {//������ť,�Ӳ˵���������
			//	@Override
				public void actionPerformed(ActionEvent e) {
				//����������ݻټ��ɱ�ɱ�ƽ����,ʵ�ֲ��˷�����ʱ����
				}
			});*/
		 sonMenuItem1.addActionListener(new ActionListener() {//������ť,�Ӳ˵������ƽ
				@Override
				public void actionPerformed(ActionEvent e) {
					new	PanelGridLayout();
					GridLayout grid=new GridLayout(6,8);
					setLayout(grid);//�ղ���
						JButton button2=new JButton();
						for (int i = 0; i<6; i++) {
							if(i>0) {//��λ��Ϊ(i,0)�������ı���i>0
								add(button2=new JButton("��"+Integer.toString(i)+"���"));//Integer.toString(i)������iת�����ַ���
							}
							//button2.setBackground(Color.WHITE);//����i,0���İ�ť����ɫ��ɰ�ɫ
							for (int j =0;j<7; j++) {
								if (i==0&&j==0) {//��λ��(0,0)�������ı�
									//add(button2=new JButton("����/����"));
								} 
								//button2.setBackground(Color.WHITE);//����һ�еİ�ť����ɫ��ɰ�ɫ
								/*if (i==0&j==6) {//���Ͻ����������
									add(button2=new JButton("������"));
									//button2.setBackground(Color.WHITE);//�����Ͻǵİ�ť����ɫ��ɰ�ɫ
								}*/
								else if (i==0&(j>=0&j<7)) {//�ж��������1-6�����������7���������
									add(button2=new JButton("����"+Integer.toString(j+1)));
								}
								else {
									JButton button=new JButton();
									add(button,BorderLayout.CENTER);
									//button.setBackground(Color.WHITE);//��ť����ɫ
									setForeground(Color.blue);//ǰ��ɫ
									setFont(new Font("����",Font.BOLD,16));//������ʽ
									button.addActionListener(new ActionListener() {//������ť
										@Override
										public void actionPerformed(ActionEvent e) {
											String str=JOptionPane.showInputDialog(button,"������γ���Ϣo(*�����*)o:","����Ի���",
											JOptionPane.PLAIN_MESSAGE);//��ÿ��Ҫд��γ̵İ�ť���öԻ���
											button.setLabel(str);
										}
									});
								}
							}
						}
						
					}
			});
		setBounds(10,10,600,300);
		setVisible(true);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		validate();
	}
}