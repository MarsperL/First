package Marsper;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
public class denglu extends JFrame{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
 //声明窗体，面板及控件
	JFrame jframe;
	JLabel jlabel,jlabel1;
	GridBagLayout gridbag;
	GridBagConstraints constraints;
	JTextField jtfield1;
	JPasswordField jpfield1;
	JButton jbutton1,jbutton2,jbutton3;
	JPanel jpanel;
	public denglu(){
	jframe = new JFrame();
	jpanel = new JPanel();
	jlabel = new JLabel();
	jlabel1 = new JLabel();
	jtfield1 = new JTextField();
	jpfield1 = new JPasswordField();
	gridbag = new GridBagLayout();
	jbutton1 = new JButton();
	jbutton2 = new JButton();
	jbutton3 = new JButton();
	init();
	jframe.setVisible(true);
	}
	/**init()初始化并显示界面*/
	void init(){
	jframe.setTitle("登录");
	//设置JPanel背景
	/*jpanel = new JPanel(){
		private static final long serialVersionUID = 1L;
	@Override
	protected void paintComponent(Graphics g) {
	super.paintComponent(g);
	ImageIcon img = new ImageIcon(denglu.class.getResource(""));
	img.paintIcon(this, g, 0, 0);
	}
	};*/
	//为JLabel,JButton初始化文本
	jlabel.setText("用户名：");
	jlabel1.setText("密 码：");
	jbutton1.setText("登录");
	jbutton2.setText("退出");
	jbutton3.setText("注册");
	//设置显示位置及屏幕大小500*400
	jframe.setBounds(450, 240, 400, 240);
	//jpanel采用GridBagLayout布局管理器
	jpanel.setOpaque(false);
	jpanel.setLayout(gridbag);
	//初始化用户名label，并添加该控件到画板
	constraints = getGridBagConstraints(0,0,1,1,0,0,GridBagConstraints.CENTER,GridBagConstraints.NONE,new Insets(10,0,10,0),0,0);
	gridbag.setConstraints(jlabel, constraints);
	jpanel.add(jlabel);
	//初始化用户名文本框，并添加该组件到画板
	constraints = getGridBagConstraints(1,0,1,1,0,0,GridBagConstraints.CENTER,GridBagConstraints.NONE,new Insets(10,0,10,0),100,0);
	gridbag.setConstraints(jtfield1, constraints);
	jpanel.add(jtfield1);
	//初始化密码label
	constraints = getGridBagConstraints(0,1,1,1,0,0,GridBagConstraints.CENTER,GridBagConstraints.NONE,new Insets(10,0,10,0),0,0);
	gridbag.setConstraints(jlabel1, constraints);
	jpanel.add(jlabel1);
	//初始化密码文本框
	constraints = getGridBagConstraints(1,1,1,1,0,0,GridBagConstraints.CENTER,GridBagConstraints.NONE,new Insets(10,0,10,0),100,0);
	gridbag.setConstraints(jpfield1, constraints);
	jpanel.add(jpfield1);
	//初始化注册按钮，并添加该控件到画板
	constraints = getGridBagConstraints(0,2,1,1,0,0,GridBagConstraints.CENTER,GridBagConstraints.NONE,new Insets(10,0,10,0),0,0);
	gridbag.setConstraints(jbutton3, constraints);
	jpanel.add(jbutton3);
	jbutton3.addActionListener(new ActionListener() {//监听按钮,监听退出按钮
		@Override
		public void actionPerformed(ActionEvent e) {
			if (jtfield1.getText().equals("")||jpfield1.getText().equals("")) {
				JOptionPane.showMessageDialog(jbutton2,"还未注册（￣︶￣）↗　","通知",JOptionPane.PLAIN_MESSAGE);
			} else {
				JOptionPane.showMessageDialog(jbutton2,"注册成功~(￣▽￣)~*","通知",JOptionPane.PLAIN_MESSAGE);
			}
		}
	});
	jbutton1.addActionListener(new ActionListener() {//监听按钮,监听退出按钮
		@Override
		public void actionPerformed(ActionEvent e) {
			String id=jtfield1.getText();// 取得用户名
			String key=jpfield1.getText();// 取得密码
			if(id.equals("Marsper")&&key.equals("Mark5")){// 判断是否登录成功
			// 如果登录成功
				JOptionPane.showMessageDialog(jbutton2,"登录成功(～￣▽￣)～","通知",JOptionPane.PLAIN_MESSAGE);
				jframe.setVisible(false);//将子窗口隐藏即退出
			}
			else{
			//如果登录失败  弹出提示
			JOptionPane.showMessageDialog(jbutton2,"用户名或者密码错误φ(*￣0￣)","通知",JOptionPane.ERROR_MESSAGE);
			jtfield1.setText("");//清空文本框的输入
			jpfield1.setText("");//清空密码框的输入
			}
		}
	});
	//初始化登录按钮
	constraints = getGridBagConstraints(1,2,1,1,0,0,GridBagConstraints.CENTER,GridBagConstraints.NONE,new Insets(10,0,10,0),0,0);
	gridbag.setConstraints(jbutton1, constraints);
	jpanel.add(jbutton1);
	//初始化退出按钮
	constraints = getGridBagConstraints(2,2,1,1,0,0,GridBagConstraints.CENTER,GridBagConstraints.NONE,new Insets(10,0,10,0),0,0);
	gridbag.setConstraints(jbutton2, constraints);
	jpanel.add(jbutton2);
	jbutton2.addActionListener(new ActionListener() {//监听按钮,监听退出按钮
		@Override
		public void actionPerformed(ActionEvent e) {	
			jframe.setVisible(false);//将子窗口隐藏即退出
		}
	});
	//添加画板到窗体
	jframe.add(jpanel);
	//窗体初始化完成
	}
	GridBagConstraints getGridBagConstraints(int gridx,int gridy,int gridwidth,int gridheight,double weightx,double weighty,int anchor,int fill,Insets insets,int ipadx,int ipady){
	return new GridBagConstraints(gridx, gridy, gridwidth, gridheight, weightx, weighty, anchor, fill, insets, ipadx, ipady);
}
}

