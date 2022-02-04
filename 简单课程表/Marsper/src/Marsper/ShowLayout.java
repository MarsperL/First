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
	//声明：
	PanelGridLayout pannelGrid;//面板
	JTabbedPane p;//选项卡窗格
	/*JMenuBar bar; //菜单栏
	JMenu menu;//菜单
	JMenuItem item;//菜单项 */
	JMenuBar menuBar;//菜单栏
	JMenu menu,subMenu;//菜单
	JMenuItem item1,item2,exit;//菜单项
	public ShowLayout() {	
		/*bar = new JMenuBar();
		menu = new JMenu("文件");
		item = new JMenuItem("新建");
		menu.add(item);
		bar.add(menu);
		this.setJMenuBar(bar);*/
		menuBar=new JMenuBar();//菜单栏
		menu=new JMenu("菜单");//菜单
		item1=new JMenuItem("新建",new ImageIcon("D:/eclipse workspace/Marsper/bin/Marsper/3 (2).png"));
		item2=new JMenuItem("账户设置",new ImageIcon("D:/eclipse workspace/Marsper/bin/Marsper/3 (1).png"));
		subMenu=new JMenu("切换主题");//菜单项
		exit=new JMenuItem("退出",new ImageIcon("D:/eclipse workspace/Marsper/bin/Marsper/3 (6).png"));//菜单项
		item1.setAccelerator(KeyStroke.getKeyStroke('N'));
		item2.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S,InputEvent.CTRL_MASK));
		exit.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_W,InputEvent.CTRL_MASK));
		menu.add(item1);
		menu.addSeparator();
		menu.add(item2);
		menu.add(subMenu);
		menu.add(exit);
		// JMenuItem sonMenuItem = new JMenuItem("扁平",new ImageIcon("D:/eclipse workspace/Marsper/bin/Marsper/3 (7).png"));// 创建子菜单主题立体的菜单项
	      JMenuItem sonMenuItem1=new JMenuItem("立体",new ImageIcon("D:/eclipse workspace/Marsper/bin/Marsper/3 (4).png"));// 创建子菜单主题扁平的菜单项
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
		add(buttontime,BorderLayout.SOUTH);//在窗口底部添加一个按钮用来显示时间
		buttontime.setBackground(Color.WHITE);//时间按钮为白色
		 /*Calendar date = Calendar.getInstance();
		 buttontime.setLabel(Calendar.getInstance().getTime().toString()); 设置日期和时间*/
		 SimpleDateFormat df = new SimpleDateFormat("yyyy年MM月dd日  EEEE  HH:mm");//设置日期和时间
		 buttontime.setText("(～￣▽￣)～："+df.format(new Date()));//在按钮上显示日期和时间
		 buttontime.setFont(new Font("宋体",Font.BOLD,20));//字体样式
		 buttontime.setPreferredSize(new Dimension(40,40));//按钮大小
		 buttontime.setContentAreaFilled(true);//按钮是否透明 false为透明
		 buttontime.setBorderPainted(true);//按钮是否去除边框 false为去除
		//buttontime.setBorder(BorderFactory.createRaisedBevelBorder());//将按钮设为突起状
		 //buttontime.setBorder(BorderFactory.createLoweredBevelBorder());//将按钮设为凹陷状
		 item1.addActionListener(new ActionListener() {//监听按钮
				@Override
				public void actionPerformed(ActionEvent e) {
					String str=JOptionPane.showInputDialog(item1,"输入数字改变课程表行数,n节课,输入n-5(例:有6节课,请输入1):","输入对话框o(*￣︶￣*)o",
					JOptionPane.PLAIN_MESSAGE);//给每个要写入课程的按钮设置对话框
					//int m=Integer.parseInt(str);
						//	new GridLayout(6+m,8);
						//new PanelGridLayout();
					//System.out.printf("%d",6+Integer.parseInt(str));
				}
			});
		 item2.addActionListener(new ActionListener() {//监听按钮,监听登录按钮
				@Override
				public void actionPerformed(ActionEvent e) {
					new denglu();
				}
			});
		 exit.addActionListener(new ActionListener() {//监听按钮,监听退出按钮
				@Override
				public void actionPerformed(ActionEvent e) {
					System.exit(0);//退出当前窗口	
				}
			});
		 /*sonMenuItem.addActionListener(new ActionListener() {//监听按钮,子菜单主题立体
			//	@Override
				public void actionPerformed(ActionEvent e) {
				//将立体主题摧毁即可变成扁平主题,实现不了方法暂时放置
				}
			});*/
		 sonMenuItem1.addActionListener(new ActionListener() {//监听按钮,子菜单主题扁平
				@Override
				public void actionPerformed(ActionEvent e) {
					new	PanelGridLayout();
					GridLayout grid=new GridLayout(6,8);
					setLayout(grid);//空布局
						JButton button2=new JButton();
						for (int i = 0; i<6; i++) {
							if(i>0) {//在位置为(i,0)处加入文本，i>0
								add(button2=new JButton("第"+Integer.toString(i)+"大节"));//Integer.toString(i)将数字i转化成字符型
							}
							//button2.setBackground(Color.WHITE);//将（i,0）的按钮背景色变成白色
							for (int j =0;j<7; j++) {
								if (i==0&&j==0) {//在位置(0,0)处加入文本
									//add(button2=new JButton("星期/节数"));
								} 
								//button2.setBackground(Color.WHITE);//将第一行的按钮背景色变成白色
								/*if (i==0&j==6) {//右上角输出星期日
									add(button2=new JButton("星期日"));
									//button2.setBackground(Color.WHITE);//将右上角的按钮背景色变成白色
								}*/
								else if (i==0&(j>=0&j<7)) {//判断输出星期1-6，不输出星期7输出星期日
									add(button2=new JButton("星期"+Integer.toString(j+1)));
								}
								else {
									JButton button=new JButton();
									add(button,BorderLayout.CENTER);
									//button.setBackground(Color.WHITE);//按钮背景色
									setForeground(Color.blue);//前景色
									setFont(new Font("宋体",Font.BOLD,16));//字体样式
									button.addActionListener(new ActionListener() {//监听按钮
										@Override
										public void actionPerformed(ActionEvent e) {
											String str=JOptionPane.showInputDialog(button,"请输入课程信息o(*￣︶￣*)o:","输入对话框",
											JOptionPane.PLAIN_MESSAGE);//给每个要写入课程的按钮设置对话框
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