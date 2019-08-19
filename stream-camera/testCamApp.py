import cv2
import flask
app = flask.Flask("app")
def gen():
    cap = cv2.VideoCapture(0)
    while True:
        _, frame = cap.read()
        yield (b'--frame\r\n'
               b'Content-Type: image/jpeg\r\n\r\n' + cv2.imencode('.jpg', frame)[1].tostring() + b'\r\n')
@app.route('/')
def feed():
    return flask.Response(gen(), mimetype='multipart/x-mixed-replace; boundary=frame')

if __name__ == '__main__':
    app.run(host='0.0.0.0', port = 6123, debug=True)

