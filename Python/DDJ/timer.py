import sys

from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *


class MainWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()
        self.pos_x = int(self.width() / 2)
        self.direction = 1
        self.speed = 5

    def initUI(self):
        # 윈도우 설정
        self.setGeometry(300, 300, 500, 500)  # x, y, w, h
        self.setWindowTitle('QPaint Move')

        # Timer 설정
        self.timer = QTimer(self)
        self.timer.start(1000)
        self.timer.timeout.connect(self.timeout_run)

        # 창닫기 버튼
        btn = QPushButton('Quit', self)
        btn.move(5, 5)
        btn.resize(btn.sizeHint())
        btn.clicked.connect(QCoreApplication.instance().quit)

    def paintEvent(self, event):
        #qp = QPainter()
        qp = QPushButton('TEST', self)
        self.draw_point(qp)

    def draw_point(self, qp):
        qp.move(50, 50)
        #qp.setPen(QPen(Qt.blue, 8))
        #qp.drawPoint(self.pos_x, 400)
        

    def timeout_run(self):
        if self.pos_x < 0 or self.pos_x > self.width() - 8:
            self.direction *= -1
        self.pos_x = self.pos_x + (self.direction * self.speed)
        print(self.pos_x, self.width())
        self.update()



if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainWindow = MainWindow()
    mainWindow.show()
    sys.exit(app.exec_())