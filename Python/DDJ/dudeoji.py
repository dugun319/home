import sys
import random
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *


class MyApp(QWidget):

    def __init__(self):
        super().__init__()
        self.initUI()

        # Position Pool of Dudeoji
        self.pool_position = [20, 90, 160]
        self.pos_x = 0
        self.pos_y = 0

        # activate button number
        self.act_btn_number = 0

        # Flag of repetitions
        self.count = 0

        # Total number of hit
        self.total_hit = 0

    def initUI(self):
        # set timer / interval 1500ms        
        self.timer = QTimer(self)
        self.timer.start()
        self.timer.setInterval(2000)
        self.timer.timeout.connect(self.timeout_run)
    
        # Hit or False message window

               # self.textEdit = QTextEdit()
               # self.btnPress1 = QPushButton("Button 1")
               # self.btnPress2 = QPushButton("Button 2")

               # layout = QVBoxLayout()
               # layout.addWidget(self.textEdit)
               # layout.addWidget(self.btnPress1)
               # layout.addWidget(self.btnPress2)
               # self.setLayout(layout)

        # drawing Ten background buttons
        #btn0 = QPushButton('Start', self)
        #btn0.move(20, 250)
        #btn0.resize(200, 30)
        #btn0.clicked.connect(self.timer.start())
        #self.timer.setInterval(2000)
        #self.timer.timeout.connect(self.timeout_run)


        self.btn1 = QPushButton('1', self)
        self.btn1.move(20, 20)
        self.btn1.resize(50, 50)
        self.btn1.setEnabled(False)
        self.btn1.clicked.connect(lambda temp="",push_btn_number=1: self.btnRun_clicked(push_btn_number))

        self.btn2 = QPushButton('2', self)
        self.btn2.move(90, 20)
        self.btn2.resize(50, 50)
        self.btn2.setEnabled(False)
        self.btn2.clicked.connect(lambda temp="",push_btn_number=2: self.btnRun_clicked(push_btn_number))
        
        self.btn3 = QPushButton('3', self)
        self.btn3.move(160, 20)
        self.btn3.resize(50, 50)
        self.btn3.setEnabled(False)
        self.btn3.clicked.connect(lambda temp="",push_btn_number=3: self.btnRun_clicked(push_btn_number))
        
        self.btn4 = QPushButton('4', self)
        self.btn4.move(20, 90)
        self.btn4.resize(50, 50)
        self.btn4.setEnabled(False)
        self.btn4.clicked.connect(lambda temp="",push_btn_number=4: self.btnRun_clicked(push_btn_number))
        
        self.btn5 = QPushButton('5', self)
        self.btn5.move(90, 90)
        self.btn5.resize(50, 50)
        self.btn5.setEnabled(False)
        self.btn5.clicked.connect(lambda temp="",push_btn_number=5: self.btnRun_clicked(push_btn_number))
        
        self.btn6 = QPushButton('6', self)
        self.btn6.move(160, 90)
        self.btn6.resize(50, 50)
        self.btn6.setEnabled(False)
        self.btn6.clicked.connect(lambda temp="",push_btn_number=6: self.btnRun_clicked(push_btn_number))
        
        self.btn7 = QPushButton('7', self)
        self.btn7.move(20, 160)
        self.btn7.resize(50, 50)
        self.btn7.setEnabled(False)
        self.btn7.clicked.connect(lambda temp="",push_btn_number=7: self.btnRun_clicked(push_btn_number))
        
        self.btn8 = QPushButton('8', self)
        self.btn8.move(90, 160)
        self.btn8.resize(50, 50)
        self.btn8.setEnabled(False)
        self.btn8.clicked.connect(lambda temp="",push_btn_number=8: self.btnRun_clicked(push_btn_number))
        
        self.btn9 = QPushButton('9', self)
        self.btn9.move(160, 160)
        self.btn9.resize(50, 50)
        self.btn9.setEnabled(False)
        self.btn9.clicked.connect(lambda temp="",push_btn_number=9: self.btnRun_clicked(push_btn_number))     
               
        self.setWindowTitle('DuDeoJi')
        self.setGeometry(300, 300, 230, 300)
        self.show()

    def paintEvent(self, event):
        qp = QPainter()
        qp.begin(self)
        self.draw_dudeoji(qp)
        qp.end()

    def draw_dudeoji(self, qp):
        qp.setPen(QPen(Qt.red, 5))
        qp.drawRoundedRect(self.pos_x, self.pos_y, 50, 50, 0, 0)
        qp.setPen(QPen(Qt.black,  5))
        qp.drawArc(self.pos_x+10, self.pos_y-10, 10, 10, 0 * 16, 180 * 16)
        qp.drawArc(self.pos_x+30, self.pos_y-10, 10, 10, 0 * 16, 180 * 16)

    def timeout_run(self):
        self.pos_x = int(random.choice(self.pool_position))
        self.pos_y = int(random.choice(self.pool_position))
        print(self.pos_x, self.pos_y)

        if self.pos_y == 20:
            if self.pos_x == 20:
                self.act_btn_number = 1
                self.btn1.setEnabled(True)
            elif self.pos_x == 90:
                self.act_btn_number = 2
                self.btn2.setEnabled(True)
            else:
                self.act_btn_number = 3
                self.btn3.setEnabled(True)
        elif self.pos_y == 90:
            if self.pos_x == 20:
                self.act_btn_number = 4
                self.btn4.setEnabled(True)
            elif self.pos_x == 90:
                self.act_btn_number = 5
                self.btn5.setEnabled(True)
            else:
                self.act_btn_number = 6
                self.btn6.setEnabled(True)
        else:
            if self.pos_x == 20:
                self.act_btn_number = 7
                self.btn7.setEnabled(True)
            elif self.pos_x == 90:
                self.act_btn_number = 8
                self.btn8.setEnabled(True)
            else:
                self.act_btn_number = 9
                self.btn9.setEnabled(True)

        print("act_btn_number = ", self.act_btn_number)

        # number of repetitions

        self.count += 1
        if self.count == 10:
            print("Total Score = ", self.total_hit * 10)
            self.timer.stop()

        self.update()

    def btnRun_clicked(self, push_btn_number):
        
        if push_btn_number == self.act_btn_number:
            print("Hit")
        print(push_btn_number)

        self.total_hit += 1

        self.btn1.setEnabled(False)
        self.btn2.setEnabled(False)
        self.btn3.setEnabled(False)
        self.btn4.setEnabled(False)
        self.btn5.setEnabled(False)
        self.btn6.setEnabled(False)
        self.btn7.setEnabled(False)
        self.btn8.setEnabled(False)
        self.btn9.setEnabled(False)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())
