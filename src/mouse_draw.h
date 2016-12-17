#ifndef MOUSE_DRAW_H
#define MOUSE_DRAW_H

class MousePainter
{
public:

    void draw()
    {
        img = cvCreateImage(cvSize(200, 200), IPL_DEPTH_8U, 3);
        cvZero(img);
        auto temp = cvCloneImage(img);
        cvNamedWindow("painting");;

        cvSetMouseCallback("painting", mouse_ev_wrapper, reinterpret_cast<void*>(this));

        while(true)
        {
            cvCopyImage(img, temp);
            if (drawing_box)
                draw_box(temp);
            cvShowImage("painting", temp);

            const char c = cvWaitKey(15);
            if (27 == c)
                break;
        }

        cvReleaseImage(&img);
        cvReleaseImage(&temp);
        cvDestroyWindow("painting");
    }


private:
    static void mouse_ev_wrapper(int ev, int x, int y, int flags, void* obj)
    {
        const auto mousePainter = reinterpret_cast<MousePainter*>(obj);
        mousePainter->mouse_ev(ev, x, y, flags, nullptr);
    }

    void mouse_ev(int ev, int x, int y, int, void* param)
    {
        Q_UNUSED(param)

        switch(ev)
        {
            case CV_EVENT_MOUSEMOVE: mouse_move(x, y); break;
            case CV_EVENT_LBUTTONDOWN: mouse_press(x, y); break;
            case CV_EVENT_LBUTTONUP: mouse_release(); break;
        }
    }

    void draw_box(IplImage* img)
    {
        cvRectangle(img, cvPoint(box.x, box.y), cvPoint(box.x + box.width, box.y + box.height), cvScalar(0xff, 0x00, 0x00));
    }

    void mouse_move(int x, int y)
    {
        if (drawing_box)
        {
            box.width = x - box.x;
            box.height = y - box.y;
        }
    }

    void mouse_press(int x, int y)
    {
        drawing_box = true;
        box = cvRect(x, y, 0, 0);
    }

    void mouse_release()
    {
        drawing_box = false;

        if (box.width < 0)
        {
            box.x += box.width;
            box.width *= -1;
        }

        if (box.height < 0)
        {
            box.y += box.height;
            box.height *= -1;
        }

        draw_box(img);
    }

private:
    CvRect box = cvRect(-1, -1, 0, 0);
    bool drawing_box{false};
    IplImage* img{nullptr};
};


#endif // MOUSE_DRAW_H
