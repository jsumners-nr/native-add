ARG NODE_VERSION
FROM node:${NODE_VERSION}-slim

RUN apt update && apt install -y python3 build-essential

WORKDIR /app
RUN mkdir /app/src
COPY ./src/ /app/src/
COPY binding.gyp index.js package.json test.js build.js /app/

CMD npm install && npm test
