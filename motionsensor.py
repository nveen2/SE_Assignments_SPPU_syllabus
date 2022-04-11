#Motion Detection using Frame Differencing

import cv2

class MotionTacker:

    def __init__(self, src=0):

        self.vh = cv2.VideoCapture(src)

        if not self.vh.isOpened():
            raise Exception('Video Source Not Accessible')


        self.prev_frame = None
        self.curr_frame = None
        self.next_frame = None


    def frame_difference(self):

        d1 = cv2.absdiff(self.prev_frame, self.curr_frame)

        d2 = cv2.absdiff(self.curr_frame, self.next_frame)

        diff = cv2.bitwise_and(d1, d2)
        return diff

    def track(self):
        cv2.namedWindow('Video Player')
        cv2.namedWindow('Motion')

        fps = self.vh.get(cv2.CAP_PROP_FPS)



        _, self.prev_frame = self.vh.read()
        _, self.curr_frame = self.vh.read()
        flag, self.next_frame = self.vh.read()

        while flag:
            cv2.imshow('Video Player', self.curr_frame)
            cv2.imshow('Motion', self.frame_difference())

            if cv2.waitKey(int(1/fps*1000)) == 27:
                break

            self.prev_frame = self.curr_frame
            self.curr_frame = self.next_frame
            flag, self.next_frame = self.vh.read()


    def __del__(self):
        print('in del')
        cv2.destroyAllWindows()
        if self.vh.isOpened():
            self.vh.release()


mt = MotionTacker('/Users/naveenjhajhriya/Downloads/a.mp4')
mt.track()
