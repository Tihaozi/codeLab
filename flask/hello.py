# for running:
#   127.0.0.1:5000
#   127.0.0.1:5000/hello

from flask import Flask
app = Flask(__name__)       # Create WSGI

@app.route('/')
def index():
    return 'Index Page'

# @app.route('/hello')
# def hello():
#     return '<h2>Hello World</h2>'

if __name__ == "__main__":
    app.run()

    # app.run(host='0.0.0.0')
    # This tells your operating system to listen on all public IPs.