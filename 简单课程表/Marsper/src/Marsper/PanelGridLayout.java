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
		GridLayout grid=new GridLayout(8,8);//网格布局
		//System.out.printf("%d",m);
		setLayout(grid);//空布局
		//add(new Button("星期/节数"));//GridLayout中的方法进行add调用
		//add(new Button("星期一"));
		//add(new Button("星期二"));
		//add(new Button("星期三"));
		//add(new Button("星期四"));
		//add(new Button("星期五"));
		//add(new Button("星期六"));
		//add(new Button("星期日"));
		Button button2=new Button();
		for (int i = 0; i<8; i++) {
			if(i>0) {//在位置为(i,0)处加入文本，i>0
				add(button2=new Button("第"+Integer.toString(i)+"大节"));//Integer.toString(i)将数字i转化成字符型
			}
			button2.setBackground(Color.WHITE);//将（i,0）的按钮背景色变成白色
			for (int j =0;j<7; j++) {
				if (i==0&&j==0) {//在位置(0,0)处加入文本
					add(button2=new Button("星期/节数"));
				} 
				button2.setBackground(Color.WHITE);//将第一行的按钮背景色变成白色
				if (i==0&j==6) {//右上角输出星期日
					add(button2=new Button("星期日"));
					button2.setBackground(Color.WHITE);//将右上角的按钮背景色变成白色
				}
				else if (i==0&(j>=0&j<6)) {//判断输出星期1-6，不输出星期7输出星期日
					add(button2=new Button("星期"+Integer.toString(j+1)));
				}
				else {
					Button button=new Button();
					add(button,BorderLayout.NORTH);//JButton的按钮为非平面化
					button.setBackground(Color.WHITE);//按钮背景色
					setForeground(Color.blue);//前景色
					setFont(new Font("宋体",Font.BOLD,16));//字体样式
					button.addActionListener(new ActionListener() {//监听按钮
						@Override
						public void actionPerformed(ActionEvent e) {
							String str=JOptionPane.showInputDialog(button,"请输入课程信息o(*￣︶￣*)o:","输入对话框",
							JOptionPane.PLAIN_MESSAGE);//给每个要写入课程的按钮设置对话框
							button.setLabel(str);
							//button2.setText(str);//将对话框里的文字输到按钮上
							/*if (str!=null) {  //输入测试
								System.out.println(str);
							} 
							else {
								System.out.println("还没输入呀!");
							}*/	
						}
					});
				}
			}
		}
		
	}
}

