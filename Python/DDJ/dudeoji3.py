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

        # active button number
        self.act_btn_number = 0

        # Flag of repetitions
        self.count = 0

        # Total number of hit
        self.total_hit = 0

    def initUI(self):
        # set timer / interval 800ms ~ 1400ms       
        self.timer = QTimer(self)
        self.timer.start()
        self.timer.setInterval(random.choice([800, 1100, 1400]))
        self.timer.timeout.connect(self.timeout_run)
    
         # drawing Ten background buttons

         # Operation Window Button
        self.btn0 = QPushButton('Start', self)
        self.btn0.move(20, 230)
        self.btn0.resize(200, 50)
        self.btn0.setStyleSheet("color: black;"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.857143, y2:0.857955, stop:0 rgba(10, 242, 251, 255), stop:1 rgba(224, 6, 159, 255));"
            "border-radius: 20px;")
        font_size = self.btn0.font()
        font_size.setPointSize(20)
        self.btn0.setFont(font_size)

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
        self.draw_red_rec(qp)
        qp.end()

    def draw_red_rec(self, qp):
        qp.setPen(QPen(Qt.red, 5))
        qp.drawRoundedRect(self.pos_x, self.pos_y, 50, 50, 0, 0)
        qp.setPen(QPen(Qt.black,  5))

    def select_pos(self):
        # select postion of X and Y
        self.pos_x = int(random.choice(self.pool_position))
        self.pos_y = int(random.choice(self.pool_position))
        print(self.pos_x, self.pos_y)

    def draw_dudeoji(self):
        # Decide location of Dudeoji Image
        if self.pos_y == 20:
            if self.pos_x == 20:
                self.act_btn_number = 1
                self.btn1.setEnabled(True)
                self.btn1.setStyleSheet("QPushButton{border-image: url(./ddj.png)}"
                    "QPushButton:hover{border-image: url(./ddj.png)}" 
                    "QPushButton:pressed{border-image: url(./ddj.png)}")
            elif self.pos_x == 90:
                self.act_btn_number = 2
                self.btn2.setEnabled(True)
                self.btn2.setStyleSheet("QPushButton{border-image: url(./ddj.png)}"
                    "QPushButton:hover{border-image: url(./ddj.png)}" 
                    "QPushButton:pressed{border-image: url(./ddj.png)}")
            else:
                self.act_btn_number = 3
                self.btn3.setEnabled(True)
                self.btn3.setStyleSheet("QPushButton{border-image: url(./ddj.png)}"
                    "QPushButton:hover{border-image: url(./ddj.png)}" 
                    "QPushButton:pressed{border-image: url(./ddj.png)}")
        elif self.pos_y == 90:
            if self.pos_x == 20:
                self.act_btn_number = 4
                self.btn4.setEnabled(True)
                self.btn4.setStyleSheet("QPushButton{border-image: url(./ddj.png)}"
                    "QPushButton:hover{border-image: url(./ddj.png)}" 
                    "QPushButton:pressed{border-image: url(./ddj.png)}")
            elif self.pos_x == 90:
                self.act_btn_number = 5
                self.btn5.setEnabled(True)
                self.btn5.setStyleSheet("QPushButton{border-image: url(./ddj.png)}"
                    "QPushButton:hover{border-image: url(./ddj.png)}" 
                    "QPushButton:pressed{border-image: url(./ddj.png)}")
            else:
                self.act_btn_number = 6
                self.btn6.setEnabled(True)
                self.btn6.setStyleSheet("QPushButton{border-image: url(./ddj.png)}"
                    "QPushButton:hover{border-image: url(./ddj.png)}" 
                    "QPushButton:pressed{border-image: url(./ddj.png)}")
        else:
            if self.pos_x == 20:
                self.act_btn_number = 7
                self.btn7.setEnabled(True)
                self.btn7.setStyleSheet("QPushButton{border-image: url(./ddj.png)}"
                    "QPushButton:hover{border-image: url(./ddj.png)}" 
                    "QPushButton:pressed{border-image: url(./ddj.png)}")
            elif self.pos_x == 90:
                self.act_btn_number = 8
                self.btn8.setEnabled(True)
                self.btn8.setStyleSheet("QPushButton{border-image: url(./ddj.png)}"
                    "QPushButton:hover{border-image: url(./ddj.png)}" 
                    "QPushButton:pressed{border-image: url(./ddj.png)}")
            else:
                self.act_btn_number = 9
                self.btn9.setEnabled(True)
                self.btn9.setStyleSheet("QPushButton{border-image: url(./ddj.png)}"
                    "QPushButton:hover{border-image: url(./ddj.png)}" 
                    "QPushButton:pressed{border-image: url(./ddj.png)}")

        print("act_btn_number = ", self.act_btn_number)

    def btn_earse(self):

        self.btn0.setText("")
        self.btn1.setEnabled(False)
        self.btn1.setStyleSheet("")
        self.btn2.setEnabled(False)
        self.btn2.setStyleSheet("")
        self.btn3.setEnabled(False)
        self.btn3.setStyleSheet("")
        self.btn4.setEnabled(False)
        self.btn4.setStyleSheet("")
        self.btn5.setEnabled(False)
        self.btn5.setStyleSheet("")
        self.btn6.setEnabled(False)
        self.btn6.setStyleSheet("")
        self.btn7.setEnabled(False)
        self.btn7.setStyleSheet("")
        self.btn8.setEnabled(False)
        self.btn8.setStyleSheet("")
        self.btn9.setEnabled(False)
        self.btn9.setStyleSheet("")    
        

    def timeout_run(self):

        self.select_pos()

        self.draw_dudeoji()        

        # Count the number of repetitions
        self.count += 1

        self.btn_earse()

        self.update()

    def btnRun_clicked(self, push_btn_number):

        str_yelling = random.choice(["AYA!", "TTaelyeola!", "TTottaelyeo!"])
        self.btn0.setText(str_yelling)

        if push_btn_number == self.act_btn_number:
            print("Hit")
        print(push_btn_number)

        self.total_hit += 1
        
        self.print_score()

    def print_score(self):
        if self.count == 10:
            self.timer.stop()
            font_size = self.btn0.font()
            font_size.setPointSize(15)
            self.btn0.setFont(font_size)
            str_score = "Your score is " + str(self.total_hit*10)
            self.btn0.setText(str_score)




if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())
