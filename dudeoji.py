import sys
import random
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *


class MyApp(QWidget):

  def __init__(self):
      super().__init__()
      self.initUI()

  def initUI(self):
      btn1 = QPushButton('1', self)
      btn1.move(20, 20)
      btn1.resize(50, 50)           

      btn2 = QPushButton('2', self)
      btn2.move(90, 20)
      btn2.resize(50, 50)
      
      btn3 = QPushButton('3', self)
      btn3.move(160, 20)
      btn3.resize(50, 50)
      
      btn4 = QPushButton('4', self)
      btn4.move(20, 90)
      btn4.resize(50, 50)
      
      btn5 = QPushButton('5', self)
      btn5.move(90, 90)
      btn5.resize(50, 50)
      
      btn6 = QPushButton('6', self)
      btn6.move(160, 90)
      btn6.resize(50, 50)
      
      btn7 = QPushButton('7', self)
      btn7.move(20, 160)
      btn7.resize(50, 50)
      
      btn8 = QPushButton('8', self)
      btn8.move(90, 160)
      btn8.resize(50, 50)
      
      btn9 = QPushButton('9', self)
      btn9.move(160, 160)
      btn9.resize(50, 50)   
      
      self.setWindowTitle('DuDeoJi')
      self.setGeometry(300, 300, 230, 230)
      self.show()

      btn0 = QPushButton(self)
      btn0.setStyleSheet("QPushButton{border-image: url(./ddj.png)}")
         #"QPushButton:hover{border-image: url(./1.png)}" 
         #"QPushButton:pressed{border-image: url(./1.png)}")
      btn0.move(90, 20)
      btn0.resize(50, 50)
      btn0.clicked.connect(QCoreApplication.instance().quit)
      self.show()




if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())