<template>
  <v-app dark>
    <v-app-bar app color="primary" dark>
      <div class="d-flex align-center">
        <v-img
          alt="Vuetify Logo"
          class="shrink mr-2"
          contain
          src="https://cdn.vuetifyjs.com/images/logos/vuetify-logo-dark.png"
          transition="scale-transition"
          width="40"
        />

        <v-img
          alt="Vuetify Name"
          class="shrink mt-1 hidden-sm-and-down"
          contain
          min-width="100"
          src="https://cdn.vuetifyjs.com/images/logos/vuetify-name-dark.png"
          width="100"
        />
      </div>

      <v-spacer></v-spacer>
      <v-text-field v-model="textField"></v-text-field>
      <v-btn v-on:click="endGame(godMessage)">God Mode Hit Treasure</v-btn>
      <v-btn v-on:click="resetGame(resetMessage)">Reset Treasure</v-btn>
      <v-btn v-on:click="sendMessage(message)">Search Treasure</v-btn>
      <v-btn id="getBuzzer" v-on:click="getStatusBuzzer(getBuzzerJSON, $event)"
        >Game Status</v-btn
      >
    </v-app-bar>

    <v-main>
      <v-card elevation= 10 dark>
        <v-card-title>Status LED Controller</v-card-title>
        <v-card-text>BuzzerPos: {{ statusBuzzer.buzzerPosition }} </v-card-text>
        <v-card-text>TresurePos: {{ statusBuzzer.treasurePlace }}</v-card-text>
        <v-card-text>leaderPos: {{ statusBuzzer.leaderPos }}</v-card-text>
      </v-card>
    </v-main>
  </v-app>
</template>

<script lang="ts">
import Vue from "vue";

export default Vue.extend({
  name: "App",

  components: {},
  methods: {
    sendMessage: function(message: JSON) {
      //console.log(JSON.stringify(message))
      console.log(this.connection);

      if (message != null) {
        this.connection.send(JSON.stringify(message));
      }
    },
    resetGame: function(rmessage: JSON) {
      //console.log(JSON.stringify(message))
      this.connection.send(JSON.stringify(rmessage));
    },
    endGame: function(rmessage: JSON) {
      //console.log(JSON.stringify(message))
      this.connection.send(JSON.stringify(rmessage));
    },
    getStatusBuzzer: function(getBuzzerJSON: JSON) {
      this.connection.send(JSON.stringify(getBuzzerJSON));

    }
  },
  data: function() {
    return {
      connection: null,
      message: {
        // eslint-disable-next-line prettier/prettier
        "setVars": {
          // eslint-disable-next-line prettier/prettier
        "isBuzzerHit": true
        }
      },
      // eslint-disable-next-line prettier/prettier
      resetMessage: { listPrograms: true },
      getBuzzerJSON: { getVars: true },
      statusBuzzer: {},
      textField: 0,
      jsonData: {}
    };
  },
  computed: {
    godMessage() {
      // eslint-disable-next-line no-var
      var setMessage = { "setVars": {"buzzerPosition": 0}};
      setMessage.setVars.buzzerPosition = this.textField;
      return setMessage;
    }
  },
  created: function() {
    console.log("Starting WebSocket Connection.");
    this.connection = new WebSocket("ws://192.168.137.62:81");

    this.connection.onopen = function(event) {
      console.log(event);
      console.log("Successfull connected.");
    };

    this.connection.onmessage = function(event) {
      console.log(event);
      console.log(event.data);
      console.log(JSON.parse(event.data));
      //this.jsonData = JSON.parse(event.data);
    };
  }
  //
});
</script>

<style>
.v-btn {
  margin: 10px;
}
.v-card {
  margin: 10px;
  border-radius: 5px;
  color: black;
  width: 400px;
}
</style>